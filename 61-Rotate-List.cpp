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
    ListNode* rotateRight(ListNode* head, int k) {
        // just store the list in vector to index them
        // iterate from the last element and seperate the last k elements
        // by make the next of the k - 1 element = null and last element's next is the first element in the list

        if(!head)return head;
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }

        int n = nodes.size();
        k %= n;
        if(!k) return head;

        nodes[n - k - 1]->next = nullptr;
        nodes[n - 1]->next = head;
        return nodes[n - k];
    }
};