class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size() < b.size();
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), comp);
        unordered_map<string, bool> vis;
        vector<string> ans;
        for(auto a: folder){
            string cur = "";
            bool valid = 1;
            for(int i = 0;i < a.size() && valid;i++){
                cur += a[i];
                if(vis.count(cur) && i < a.size() - 1 && a[i + 1]=='/')
                    valid = 0;
            }
            if(valid) {
                vis[a] = 1;
                ans.push_back(a);
            }
        }
        return ans;
    }
};