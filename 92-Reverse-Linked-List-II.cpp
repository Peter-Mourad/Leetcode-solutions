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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> list;
        ListNode* cur = head;
        int i = 1;
        ListNode* before = nullptr;
        ListNode* after = nullptr;
        while(cur){
            if(i==left - 1)
                before = cur;
            if(i==right + 1) 
                after = cur;
            if(i >= left && i <= right)
                list.push_back(cur);
            i++;
            cur = cur->next;
        }
        reverse(list.begin(), list.end());
        (before) ? before->next = list[0] : head = list[0];
        for(int i = 0;i < list.size() - 1; i++)
            list[i]->next = list[i + 1];

        (after) ? list.back()->next = after : list.back()->next = nullptr;
        return head;
    }
};