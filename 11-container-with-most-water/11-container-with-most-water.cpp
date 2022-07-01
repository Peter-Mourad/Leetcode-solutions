int min(int &a, int &b){
    if(a < b)return a;
    return b;
}
int max(int &a, int &b){
    if(a > b)return a;
    return b;
}
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int l = 0,r = n - 1;l<=r;){
            ans = max(ans,min(height[l],height[r]) * (r - l));
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};