class TrieNode{
public:
    TrieNode* child[26];
    bool isWord;
    int freq;
    TrieNode(){
        for(int i = 0;i < 26;i++) child[i] = nullptr;
        isWord = false, freq = 0;
    }
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* cur = root;
        for(auto &ch: word){
            if(!cur->child[ch - 'a'])
                cur->child[ch - 'a'] = new TrieNode();
            cur = cur->child[ch - 'a'];
            cur->freq++;
        }
        cur->isWord = true;
    }

    int getFreq(string &word){
        int ans = 0;
        TrieNode* cur = root;
        for(auto &ch: word){
            cur = cur->child[ch - 'a'];
            ans += cur->freq;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* trie = new Trie();
        for(auto & word: words)
            trie->insert(word);
        vector<int> ans(words.size());
        for(int i = 0;i < words.size();i++){
            ans[i] = trie->getFreq(words[i]);
        }
        return ans;
    }
};