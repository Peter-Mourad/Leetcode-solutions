class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto comp = [](vector<int> &v1, vector<int> &v2) ->bool{
            return v1[1] > v2[1];  
        };
        sort(boxTypes.begin(),boxTypes.end(),comp);
        long long ans = 0;
        for(auto p : boxTypes){
            ans+=min(p[0], truckSize) * p[1];
            truckSize-=min(p[0], truckSize);
            if(!truckSize)break;
        }
        return ans;
    }
};