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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur){
            ListNode* temp = cur;
            int f = 0;
            while(temp && temp->val == cur->val){
                temp = temp->next;
                f++;
            }
            if(f > 1){
                if(prev) prev->next = temp;
                else head = temp;
                cur = temp;
                continue;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};