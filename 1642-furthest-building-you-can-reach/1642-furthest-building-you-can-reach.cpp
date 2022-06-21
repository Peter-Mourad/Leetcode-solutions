class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> h;
        for(int i = 1; i < heights.size(); i++){
            if(heights[i - 1] >= heights[i])continue;
            h.push(heights[i] - heights[i - 1]);
            bricks -= heights[i] - heights[i - 1];
            while(bricks < 0 && ladders && !h.empty()){
                bricks += h.top();
                h.pop();
                ladders--;
            }
            if(bricks < 0) return i - 1;
        }
        return heights.size() - 1;
    }
};