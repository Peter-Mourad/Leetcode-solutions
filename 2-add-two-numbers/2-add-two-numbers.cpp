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
    void dfs(ListNode* l1, ListNode* l2, bool add){
        if(l1==nullptr && l2==nullptr) return;
        
        if(l1->next==nullptr && l2->next)
            l1->next = new ListNode();
        if(l2->next==nullptr && l1->next)
            l2->next = new ListNode();
        
        l1->val+=l2->val + add;
        bool rem = l1->val >= 10;
        l1->val%=10;
        if(l1->next==nullptr && l2->next==nullptr && rem){
            l1->next = new ListNode(1);
            return ;
        }
        dfs(l1->next,l2->next,rem);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        dfs(l1, l2, 0);
        return l1;
    }
};