class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        for(auto a : nums)
            s.insert(a);
        auto it = s.begin();
        for(int i = 0;i < s.size();i++,it++){
            nums[i] = *it;
        }
        return s.size();
    }
};