class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "",b = "";
        for(auto str: word1)
            a += str;
        for(auto str: word2)
            b += str;
        return a==b;
    }
};