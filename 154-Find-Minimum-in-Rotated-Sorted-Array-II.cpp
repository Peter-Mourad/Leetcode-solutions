class Solution {
public:
    int findMin(vector<int>& nums) {
        // make binary search compared to last element in the rotated array
        // if current element is greater than last element then go up
        // else go down
        while(nums.size() > 1 && nums.back()==nums[0])
            nums.pop_back();
        int n = nums.size();
        cout<<n<<endl;
        int l = 0,r = n - 1, mid,ans = nums.back();
        while(l <= r){
            mid = (l + r) >> 1;
            if(nums[mid] > nums.back())
                l = mid + 1;
            else
                r = mid - 1,ans = nums[mid];
        }
        return ans;
    }
};