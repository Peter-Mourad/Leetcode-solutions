class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        for(int i = 0;i < n;i++){
            int sz = 0, count = 0, j = i;
            while(j < n && sz + words[j].size() <= maxWidth){
                sz += words[j++].size() + 1;
                count++;
            }
            string res = "";
            if(j==n){
                for(;i < j;i++){
                    res += words[i];
                    if(i==j - 1)break;
                    res += ' ';
                }
                res += string(maxWidth - res.size(), ' ');
                ans.push_back(res);
                break;
            }
            int spaces = maxWidth - (sz - count--);
            int extra = count ? spaces % count : 0;
            for(;i < j;i++){
                res += words[i];
                if(i==j - 1)break;
                res += string(spaces / count + (extra  > 0 ? 1 : 0), ' ');
                extra--;
            }
            res += string(maxWidth - res.size(), ' ');
            ans.push_back(res);
        }
        return ans;
    }
};