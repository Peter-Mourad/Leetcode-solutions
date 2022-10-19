bool comp(pair<int,string> &p1, pair<int,string> &p2){
    if(p1.first > p2.first || 
      (p1.first==p2.first && p1.second < p2.second))
        return true;
    return false;
}
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> freq;
        for(auto a : words)
            freq[a]++;
        vector<pair<int,string>> f;
        for(auto p : freq)
            f.emplace_back(p.second,p.first);
        sort(f.begin(), f.end(), comp);
        vector<string> ans(k);
        for(int i = 0;i < k;i++)
            ans[i] = f[i].second;
        return ans;
    }
};