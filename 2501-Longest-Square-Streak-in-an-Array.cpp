class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> streak;
        sort(nums.begin(), nums.end());
        int ans = -1;
        for(auto a: nums) {
            int root = sqrt(a);
            if(root * root==a && streak.count(root))
                streak[a] = streak[root] + 1, ans = max(ans, streak[a]);

            streak[a] = max(streak[a], 1);
        }
        return ans;
    }
};