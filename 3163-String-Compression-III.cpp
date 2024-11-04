class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        for(int i = 0;i < word.size();){
            int j = i;
            while(j - i < 9 && j < word.size() && word[i]==word[j])
                j++;
            
            char sz = '0' + j - i;
            ans += sz;
            ans += word[i];
            i = j;
        }
        return ans;
    }
};