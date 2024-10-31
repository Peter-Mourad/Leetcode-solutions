class Solution {
public:
    long long dp[100][100][101];
    long long solve(int r, int f, int rem, vector<int>& robot, vector<vector<int>>& factory){
        if(r==robot.size())return 0;
        long long &ret = dp[r][f][rem];
        if(~ret) return ret;

        /* 
            there are 2 options:
            option 1: if there's remaining limits rem in current factory f then repair current robot in the current factory.
            option 2: skip this factory and go to factory f + 1
        */

        ret = 1e18;
        long long res1 = 1e18, res2 = 1e18;
        if(rem)
            res1 = solve(r + 1, f, rem - 1, robot, factory) + abs(robot[r] - factory[f][0]);
        if(f + 1 < factory.size())
            res2 = solve(r, f + 1, factory[f + 1][1], robot, factory);
        return ret = min(res1, res2);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(dp, -1, sizeof(dp));
        return solve(0,0,factory[0][1], robot, factory);
    }
};