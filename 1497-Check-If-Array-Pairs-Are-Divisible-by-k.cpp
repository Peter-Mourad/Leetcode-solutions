class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mods(k);
        for(auto &a: arr)
            mods[(a % k + k) % k]++;
        
        for(int i = 0;i < k;i++){
            if(!i){
                if(mods[i] & 1) 
                    return false;
            }
            else if(mods[i] != mods[k - i]) 
                return false;
        }
        return true;
    }
};