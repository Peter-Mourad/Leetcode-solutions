class Solution {
public:
    set<string> seq;
    void solve(string &tiles, string cur, vector<bool> &used){
        if(cur!="")
            seq.insert(cur);
        for(int i = 0;i < tiles.size();i++){
            if(!used[i]){
                used[i] = 1, cur += tiles[i];
                solve(tiles, cur, used);
                used[i] = 0, cur.pop_back();
            }
        }        
    }
    int numTilePossibilities(string tiles) {
        vector<bool> used(tiles.size());
        solve(tiles, "", used);
        return seq.size();
    }
};