class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort to iterate sequentially
        sort(nums.begin(),nums.end());
        int last = -1e9 - 1,ans = 0,cur = 0;
        for(int i = 0;i < nums.size();i++){
            // if valid next element in current sequence add it
            if(nums[i]==last + 1)
                cur++,last = nums[i];
            // if the number = last number we can skip it
            // if the number != last number then update answer
            // and make another sequence from current element
            else if(nums[i]!=last){
                if(cur > ans)
                    ans = cur;
                cur = 1,last = nums[i]; 
            }
        }
        return max(ans, cur);
    }
};