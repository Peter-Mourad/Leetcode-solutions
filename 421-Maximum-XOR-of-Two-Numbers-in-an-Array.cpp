class Node{
public:
    Node* child[2];
    bool isNum;
    Node(){
        child[0] = child[1] = nullptr;
        isNum = false;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* cur = root;
        for(long i = 31; i >= 0; i--){
            long bit = ((((long)1<<i) & num) ? 1 : 0);
            if(!cur->child[bit])
                cur->child[bit] = new Node();
            cur = cur->child[bit];
        }
        cur->isNum = true;
    }

    int solve(Node* cur1, Node* cur2, long bit){
        if(!cur1 || !cur2 || !bit) return 0;

        int ans1 = 0, ans2 = 0;
        if(cur1->child[0] && cur2->child[1])
            ans1 = solve(cur1->child[0], cur2->child[1], bit>>1) + bit;
        if(cur1->child[1] && cur2->child[0])
            ans2 = solve(cur1->child[1], cur2->child[0], bit>>1) + bit;
        
        if(ans1 || ans2) 
            return max(ans1, ans2);
        
        return max(
                solve(cur1->child[0], cur2->child[0], bit>>1),
                solve(cur1->child[1], cur2->child[1], bit>>1)
            );
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for(auto a : nums){
            trie->insert(a);
        }
        Node* cur1 = trie->root;
        Node* cur2 = trie->root;
        return trie->solve(cur1, cur2, ((long)1<<31));
    }
};