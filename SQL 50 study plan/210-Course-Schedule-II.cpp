class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses);
        vector<vector<int>> adj(numCourses);
        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }

        queue<int> q;
        vector<bool> vis(numCourses);
        for(int i = 0;i < numCourses;i++){
            if(!in[i]){
                q.push(i), vis[i] = 1;
            }
        }

        int cur = 0;
        vector<int> ans;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int a = q.front();
                q.pop();
                vis[a] = 1;
                ans.push_back(a);
                for(auto b: adj[a]){
                    if(!--in[b] && !vis[b]) {
                        vis[b] = cur;
                        q.push(b);
                    }
                }
            }
        }
        return (ans.size() != numCourses ? vector<int>() : ans);
    }
};