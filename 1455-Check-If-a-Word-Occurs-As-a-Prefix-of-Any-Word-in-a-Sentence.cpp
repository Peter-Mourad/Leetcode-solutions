class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int ind = 1;
        while (ss >> word){
            if(!word.find(searchWord)) return ind;
            ind++;
        }
        return -1;
    }
};