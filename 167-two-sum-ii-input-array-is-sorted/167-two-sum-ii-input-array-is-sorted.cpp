class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> index;
        vector<int> ans;
        for(int i = 0;i < numbers.size(); i++){
            if(index[target - numbers[i]]){
                ans.push_back(index[target - numbers[i]]);
                ans.push_back(i + 1);
                return ans;
            }
            index[numbers[i]] = i + 1;
        }
        return ans;
    }
};