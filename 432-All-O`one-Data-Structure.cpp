class AllOne {
public:
    unordered_map<string, int> freq;
    set<pair<int,string>> hash;
    AllOne() {
        
    }
    
    void inc(string key) {
        if(hash.count({freq[key], key}))
            hash.erase({freq[key], key});
        freq[key]++;
        hash.insert({freq[key], key});
    }
    
    void dec(string key) {
        hash.erase({freq[key], key});
        freq[key]--;
        if(!freq[key])freq.erase(key);
        else hash.insert({freq[key], key});
    }
    
    string getMaxKey() {
        if(freq.empty()) return "";
        auto it = hash.end();
        it--;
        return (*it).second;
    }
    
    string getMinKey() {
        return (freq.empty()) ? "" : (*hash.begin()).second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */