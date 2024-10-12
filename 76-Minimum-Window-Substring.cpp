class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> freq, cur;
        for(auto &ch: t)
            freq[ch]++;
        int left = 0;
        pair<int,int> ans = {0,INT_MAX};
        for(int i = 0;i < s.size();i++){
            cur[s[i]]++;
            while(cur[s[left]] > freq[s[left]]){
                cur[s[left++]]--;
            }

            bool match = 1;
            for(auto &p: freq){
                if(cur[p.first] < p.second){
                    match = 0;
                    break;
                }
            }
            if(match){
                for(;left <= i;left++){
                    cur[s[left]]--;
                    if(cur[s[left]] < freq[s[left]]){
                        if(ans.second - ans.first > i - left)
                            ans = {left,i};
                        left++;
                        break;
                    }
                }
            }
        }
        return (ans.second==INT_MAX) ? "" : s.substr(ans.first, ans.second - ans.first + 1);
    }
};