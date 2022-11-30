class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> f;
        for(auto a : arr){
            f[a]++;
        }
        map<int,int> freq;
        for(auto p : f){
            freq[p.second]++;
            if(freq[p.second] > 1)
                return false;
        }
        return true;
    }
};