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
        int n = lists.size();
        set<pair<int,int> > s;
        for(int i = 0;i < n;i++){
            if(lists[i]==nullptr)continue;
            s.insert({lists[i]->val, i});
            lists[i] = lists[i]->next;
        }
        ListNode *ans = new ListNode();
        auto temp= ans;
        while(!s.empty()){
            auto p = *s.begin();
            s.erase(p);
            if(lists[p.second]!=nullptr){
                s.insert({lists[p.second] -> val, p.second});
                lists[p.second] = lists[p.second]->next;
            }
            ans->next = new ListNode();
            ans = ans->next;
            ans->val = p.first;
        }
        return temp->next;
    }
};