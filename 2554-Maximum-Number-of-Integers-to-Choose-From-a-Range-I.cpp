class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int ans = 0;
        for(auto a : banned) cout<<a<<endl;
        for(int i = 1,j = 0;i <= n && maxSum >= i;i++){
            int temp = j;
            while(j < banned.size() && i==banned[j]) {
                j++;
            }
            if(temp!=j)continue;
            else maxSum-=i, ans++;
        }
        return ans;
    }
};