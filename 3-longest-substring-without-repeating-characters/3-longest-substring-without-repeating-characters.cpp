class Solution {
public:
    int lengthOfLongestSubstring(string x) {
        int ans = 0,cur = 0;
        vector<int> last(200,-1);
        for(int i = 0;i < x.size();i++){
            if(~last[x[i]]){
                for(int j = i - cur;j < i;j++){
                    cur--;
                    last[x[j]] = -1;
                    if(x[j]==x[i])break;
                }                
            }
            last[x[i]] = i, cur++;
            if(cur > ans) ans = cur;
        }
        return ans;
    }
};