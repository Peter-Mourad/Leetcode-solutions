class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int> > ans(n);
        ans[0] = {1};
        if(n==1)return ans;
        ans[1] = {1,1};
        vector<int> temp;
        for(int i = 2;i < n;i++){
            temp.clear();
            temp.push_back(1);
            for(int j = 0;j < i - 1;j++)
                temp.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            temp.push_back(1);
            ans[i] = temp;
        }
        return ans;
    }
};