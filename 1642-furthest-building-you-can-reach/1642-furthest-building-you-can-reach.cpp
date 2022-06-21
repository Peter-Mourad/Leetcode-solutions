class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> h;
        for(int i = 1; i < heights.size(); i++){
            if(heights[i - 1] >= heights[i])continue;
            h.insert(heights[i] - heights[i - 1]);
            bricks -= heights[i] - heights[i - 1];
            while(bricks < 0 && ladders && !h.empty()){
                auto it = h.end();
                it--;
                bricks += *it;
                h.erase(it);
                ladders--;
            }
            if(bricks < 0)return i - 1;
        }
        return heights.size() - 1;
    }
};