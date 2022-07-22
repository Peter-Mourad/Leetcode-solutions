/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<int> v;
        while(head!=nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        ListNode* temp = new ListNode();
        head = temp;
        for(int i = 0;i < v.size();i++){
            if(v[i] < x){
                temp->next = new ListNode(v[i]);
                temp = temp->next;
            }
        }
        for(int i = 0;i < v.size();i++){
            if(v[i] >= x){
                temp->next = new ListNode(v[i]);
                temp = temp->next;
            }
        }
        return head->next;
    }
};