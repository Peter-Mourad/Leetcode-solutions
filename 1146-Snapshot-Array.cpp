class SnapshotArray {
public:
    vector<int> snapShot;
    int id;
    map<int, vector<pair<int,int>> > mp;
    SnapshotArray(int length) {
        snapShot = vector<int> (length);
        id = 0;
        for(int i = 0;i < length; i++)
            mp[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        snapShot[index] = val;
        if(!mp[index].empty() && mp[index].back().first==id)
            mp[index].pop_back();
        mp[index].push_back({id, val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        // binary search for the snap and return the value
        int ind = lower_bound(mp[index].begin(), mp[index].end(), make_pair(snap_id + 1, 0)) - mp[index].begin();
        return mp[index][ind - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */