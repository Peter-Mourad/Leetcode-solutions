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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        int rem = 0;
        while(l1 || l2){
            if(!l1 && !l2) break;
            if(!l1) 
                cur->next = l2;
            else if(!l2) 
                cur->next = l1;
            else 
                cur->next = new ListNode(l1->val + l2->val);
            
            cur->next->val += rem;
            rem = (cur->next->val > 9) ? 1 : 0;
            cur->next->val %= 10;
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(rem) cur->next = new ListNode(1);
        return ans->next;
    }
};