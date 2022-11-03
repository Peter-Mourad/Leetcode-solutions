class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> freq;
        for(auto a : words){
            freq[a]++;
        }
        int ans = 0;
        for(auto p : freq){
            if(p.first[0]==p.first[1]){
                ans += p.second / 2 * 4;
                freq[p.first] -= p.second / 2 * 2;
            }
            else{
                string temp = p.first;
                reverse(temp.begin(),temp.end());
                int mn = min(freq[temp], p.second);
                freq[temp]-=mn;
                freq[p.first]-=mn;
                ans+=mn * 4;
            }
        }
        for(auto p : freq){
            if(p.first[0]==p.first[1] && p.second){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};