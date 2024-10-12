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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1 2 3 4 5
        // divide them to groups and reverse them independently
        // [1, 2] , [3, 4] , [5]
        // [2, 1] , [4, 3] , [5]
        // end of each group -> head of next group
        vector<vector<ListNode*> > groups;
        ListNode* temp = head;
        vector<ListNode*> group;
        while(temp!=nullptr){
            group.push_back(temp);
            if(group.size()==k){
                groups.push_back(group);
                group.clear();
            }
            temp = temp->next;
        }
        if(!group.empty())
            groups.push_back(group);
        // reverse each group
        for(int i = groups.size() - (groups.back().size()==k ? 1 : 2); ~i; i--){
            cout<<i<<'\n';
            for(int j = groups[i].size() - 1; j; j--){
                // cout<<(groups[i][j]->val)<<' '<<(groups[i][j - 1]->val)<<'\n';
                groups[i][j]->next = groups[i][j - 1];
            }
            if(i < groups.size() - 1){
                if(i==groups.size() - 2 && groups.back().size()!=k)
                    groups[i][0]->next = groups[i + 1][0];
                else
                    groups[i][0]->next = groups[i + 1].back();
            }
            else
                groups[i][0]->next = nullptr;
        }
        return groups[0].back();
    }
};