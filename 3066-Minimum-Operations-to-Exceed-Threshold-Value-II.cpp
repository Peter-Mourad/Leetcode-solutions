class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> s;
        for(auto a :nums)
            s.insert(a);
        while(*s.begin() < k){
            auto no1 = *s.begin();
            s.erase(s.begin());
            auto no2 = *s.begin();
            s.erase(s.begin());
            s.insert(min(no1, no2) * 2 + max(no1,no2));
        }
        return nums.size() - s.size();
    }
};