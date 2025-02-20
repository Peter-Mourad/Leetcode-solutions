class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s;
        for(auto a: nums) s.insert(a);
        int n = nums.size();
        for(int i = 0;;i++){
            string num = "";
            for(int j = n - 1; ~j; j--){
                num += (i & (1<<j) ? '1' : '0');
            }
            if(!s.count(num)) return num;
        }
        return "";
    }
};