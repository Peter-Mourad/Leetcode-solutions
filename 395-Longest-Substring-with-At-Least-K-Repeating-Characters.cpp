class Solution {
public:
    int longestSubstring(string s, int k) {
        // see for each number of distinct characters d in the substring
        // we need substring with size >= d * k
        int n = s.size(), ans = 0;
        for(int d = 1;d <= 26; d++){
            int st = 0, curChars = 0;
            vector<int> freq(26);
            for(int i = 0;i < n;i++){
                if(!freq[s[i] - 'a']) curChars++;
                freq[s[i] - 'a']++;
                while(curChars > d){
                    freq[s[st] - 'a']--;
                    if(!freq[s[st] - 'a']) curChars--;
                    st++;
                }
                if(i - st + 1 >= d * k){
                    bool valid = 1;
                    for(int j = 0;j < 26 && valid;j++){
                        if(freq[j] && freq[j] < k)
                            valid = 0;
                    }
                    if(valid)
                        ans = max(ans, i - st + 1);
                }
            }
        }
        return ans;
    }
};