class Solution {
public:
    vector<int> isPrime;
    Solution(){
        isPrime = vector<int> (1e5,1);
        seive();
    }
    void seive(){
        isPrime[0] = isPrime[1] = 0;
        for(int i = 2;i * i < 1e5;i++){
            if(!isPrime[i]) continue;
            for(int j = i * 2;j < 1e5;j+=i)
                isPrime[j] = 0;
        }
    }

    int minOperations(int n, int m) {
        if(isPrime[n] || isPrime[m]) return -1;
        map<int, int> par;
        vector<long long> vis(1e5, 1e12);
        queue<int> q;
        q.push(n);
        par[n] = -1;
        vis[n] = n;
        int cur = 0;
        while(!q.empty()){
            cur++;
            int sz = q.size();
            while(sz--){
                int a = q.front();
                q.pop();
                string x = to_string(a);
                for(int i = 0;i < x.size();i++){
                    if((x[i] > '0' && i) || (x[i] > '1' && !i)){
                        x[i]--;
                        int res = stoi(x);
                        if(!isPrime[res] && vis[res] > vis[a] + res){
                            par[res] = a;
                            vis[res] = vis[a] + res;
                            q.push(res);
                        }
                        x[i]++;
                            
                    }
                    if(x[i] < '9'){
                        x[i]++;
                        int res = stoi(x);
                        if(!isPrime[res] && vis[res] > vis[a] + res){
                            par[res] = a;
                            vis[res] = vis[a] + res;
                            q.push(res);
                        }
                        x[i]--;
                    }
                }
            }
        }
        
        if(vis[m]==1e12) return -1;
        int ans = 0;
        while(~par[m]){
            ans += m;
            m = par[m];
        }
        return ans + n;
    }
};