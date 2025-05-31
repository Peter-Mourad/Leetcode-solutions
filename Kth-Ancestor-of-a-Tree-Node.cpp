class TreeAncestor {
public:
    int n, l, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout;

    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    TreeAncestor(int n, vector<int>& parent) {
        tin.resize(n), tout.resize(n);
        timer = 0, l = ceil(log2(n));
        up = vector<vector<int>> (n, vector<int> (l + 1));
        adj = vector<vector<int> > (n); 
        for(int i = 1;i < parent.size();i++)
            adj[parent[i]].push_back(i);
        
        dfs(0, 0);
    }
    
    int getKthAncestor(int node, int k) {
        while(k > 0){
            if(!node) return -1;
            int j = 0;
            while (j + 1 <= l &&  (1 << (j + 1)) <= k && up[node][j + 1]) {
                j++;
            }
            node = up[node][j];
            k -= 1<<j;
        }
        return node;
    }
};