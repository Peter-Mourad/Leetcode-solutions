class Solution {
public:
    int dp[2001][2003];
    bool solve(int i, int jump, vector<int> &stones){
        if(i==stones.size() - 1)
            return 1;
        int &ret = dp[i][jump];
        if(~ret) return ret;
        ret = 0;
        for(int j = i + 1;j < stones.size();j++){
            // validate jump from stone[i] to stone[j]
            int diff = stones[j] - stones[i];
            if(diff >= jump - 1 && diff <= jump + 1)
                ret |= solve(j, stones[j] - stones[i], stones);
        }
        return ret;
    }
    bool canCross(vector<int>& stones) {
        if(stones.size() > 1 && stones[1]!=1)
            return false;
        memset(dp, -1 , sizeof(dp));
        return solve(1,1, stones);
    }   
};