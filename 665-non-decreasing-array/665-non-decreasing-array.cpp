class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = 0;
        bool yes = 1;
        vector<int> temp = nums;
        for(int i = 1; i< nums.size() && yes;i++){
            if(temp[i] < temp[i - 1]){
                if(modified)yes = 0;
                modified = 1;
                temp[i] = temp[i - 1];
            }
        }
        if(yes)return 1;
        modified = 0;
        for(int i = 0; i + 1 < nums.size();i++){
            if(nums[i] > nums[i + 1]){
                if(modified)return false;
                modified = 1;
                nums[i] = nums[i + 1];
            }
            if(i && nums[i] < nums[i - 1])return false;
        }
        return true;
    }
};