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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> s;
        for(auto list : lists){
            if(list==nullptr)continue;
            while(list->next!=nullptr){
                s.insert(list->val);
                list = list->next;
            }
            s.insert(list->val);
        }
        ListNode* ans = new ListNode();
        auto temp = ans;
        for(auto it = s.begin();it!=s.end();it++){
            ans->next = new ListNode(*it);
            ans = ans->next;            
        }
        return temp->next;
    }
};