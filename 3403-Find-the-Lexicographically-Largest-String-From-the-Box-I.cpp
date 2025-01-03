class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int n = word.size();
        int mx_sz = n - numFriends + 1;
        string ans = "";
        char mx_char = 'a';
        for(auto ch: word) mx_char = max(mx_char, ch);
        for(int i = 0;i < n;i++){
            if(word[i]==mx_char){
                string cur = "";
                for(int j = i;j < i + mx_sz && j < n;j++)
                    cur += word[j];
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};