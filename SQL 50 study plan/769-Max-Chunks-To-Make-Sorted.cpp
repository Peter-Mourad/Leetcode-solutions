class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        unordered_set<int> need, have;
        int ans = 0;
        for(int i = 0;i < arr.size();i++){
            have.insert(arr[i]);
            if(have.find(i)==have.end())
                need.insert(i);
            else
                need.erase(i);
            
            if(need.find(arr[i]) != need.end())
                need.erase(arr[i]);
            
            if(need.empty())
                ans++;
        }
        return ans + (!need.empty());
    }
};