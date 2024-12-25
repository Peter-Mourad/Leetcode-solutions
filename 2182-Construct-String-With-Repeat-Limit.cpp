class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> f(26);
        vector<pair<char, int> > freq;
        for(auto a: s) f[a - 'a']++;
        for(char i = 'a' ; i <= 'z' ;i++) {
            if(f[i - 'a'])
                freq.push_back({i, f[i - 'a']});
        }
        
        string ans = "";
        while(!freq.empty()){
            auto &p = freq.back();
            int mn = min(p.second, repeatLimit);
            p.second -= mn;
            ans += string(mn, p.first);
            if(p.second){
                int l = freq.size() - 2;
                bool found = 0;
                while(freq.size() > 1 && !freq[freq.size() - 2].second)
                    freq.erase(prev(freq.end(), 2));
                if(freq.size() > 1){
                    freq[freq.size() - 2].second--;
                    ans += freq[freq.size() - 2].first;
                }
                else break;
            }
            while(!freq.empty() && !freq.back().second)
                freq.pop_back();
        }
        return ans;
    }
};