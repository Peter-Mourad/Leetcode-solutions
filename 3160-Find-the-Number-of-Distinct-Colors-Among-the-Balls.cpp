class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> color_freq, color;
        int q = queries.size();
        vector<int> ans(q);
        for(int i = 0;i < q; i++){
            int ind = queries[i][0], col = queries[i][1];
            if(color_freq.find(color[ind]) != color_freq.end()){
                if(color_freq[color[ind]]==1)
                    color_freq.erase(color[ind]);
                else
                    color_freq[color[ind]]--;
            }
            color_freq[col]++;
            color[ind] = col;
            ans[i] = color_freq.size();
        }
        return ans;
    }
};