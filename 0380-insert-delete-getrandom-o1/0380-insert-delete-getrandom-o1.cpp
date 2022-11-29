class RandomizedSet {
public:
    set<int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool ans = (s.find(val)==s.end());
        s.insert(val);
        return ans;
    }
    
    bool remove(int val) {
        bool ans = s.find(val)!=s.end();
        s.erase(val);
        return ans;
    }
    
    int getRandom() {
        return *next(s.begin(), rand() % s.size());
    }
};