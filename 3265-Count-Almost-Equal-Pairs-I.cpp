class Solution {
public:
    int countPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        for(auto a: nums){
            string no = to_string(a);
            unordered_set<int> cur;
            cur.insert(stoi(no));
            no = string(7 - no.size(), '0') + no;
            for(int i = 0;i < no.size();i++){
                for(int j = i + 1;j < no.size();j++){
                    swap(no[i], no[j]);
                    cur.insert(stoi(no));
                    swap(no[i], no[j]);
                }
            }
            for(auto p: cur){
                if(freq.find(p) != freq.end())
                    ans += freq[p];
            }
            freq[a]++;
        }
        return ans;
    }
};