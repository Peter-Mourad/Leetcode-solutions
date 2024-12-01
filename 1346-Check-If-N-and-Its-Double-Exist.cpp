class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> vis;
        for(auto a: arr){
            if((a % 2==0 && vis.count(a / 2)) || vis.count(a * 2))
                return true;
            vis.insert(a);
        }
        return false;
    }
};