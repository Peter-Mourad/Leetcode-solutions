class TimeMap {
public:
    map<string, vector<pair<int,string>> > mp;
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp[key].empty() || 
        (!mp[key].empty() && mp[key][0].first > timestamp)) 
            return "";

        int ind = lower_bound(mp[key].begin(), mp[key].end(), make_pair(timestamp + 1, "")) - mp[key].begin();
        return mp[key][ind - 1].second;
    }
};