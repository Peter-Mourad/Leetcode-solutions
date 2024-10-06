class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream s1(sentence1), s2(sentence2);
        vector<string> w1,w2;
        string word;
        while(s1 >> word)
            w1.push_back(word);
        while(s2 >> word)
            w2.push_back(word);

        if(w1.size() < w2.size())swap(w1,w2);

        int sz1 = w1.size(), sz2 = w2.size();
        int i = 0, j = 0;
        
        while(i < sz2 && w1[i]==w2[i]) i++;
        while(j < sz2 && w1[sz1 - j - 1]==w2[sz2 - j - 1]) j++;

        return i + j >= sz2;
    }
};