class TrieNode{
public:
    TrieNode* child[10];
    bool isNum;
    TrieNode(){
        for(int i = 0;i < 10;i++)
            child[i] = nullptr;
        isNum = false;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(int &a){
        string num = to_string(a);
        TrieNode* cur = root;
        for(auto &d: num){
            if(!cur->child[d - '0'])
                cur->child[d - '0'] = new TrieNode();
            cur = cur->child[d - '0'];
        }
        cur->isNum = true;
    }

    int maxCommonPrefix(TrieNode* cur, int &a){
        int ans = 0;
        string num = to_string(a);
        for(auto &d: num){
            if(!cur->child[d - '0'])
                break;
            cur = cur->child[d - '0'];
            ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* trie = new Trie();
        for(auto &num: arr1)
            trie->insert(num);
        int ans = 0;
        for(auto &num: arr2)
            ans = max(ans, trie->maxCommonPrefix(trie->root, num));
        
        return ans;
    }
};