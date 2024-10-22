class Solution {
public:
    void topoligicalSort(int &k, vector<vector<int>> &adj, vector<int> &inDegree, vector<int> &order){
        queue<int> q;
        for(int i = 1;i <= k;i++){
            if(!inDegree[i]){
                q.push(i);
            }
        }
        
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int a = q.front();
                q.pop();
                order.push_back(a);
                for(auto b: adj[a]){
                    if(!--inDegree[b])
                        q.push(b);
                }
            }
            lvl++;
        }
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        /*
            Approach:
            Firstly see the conditions as a directed graph when there's a row condition saying that 1 must be in a row before 2 make directed edge 1->2
            The idea is to order them by topolical sort.
            when there's no inDegree numbers they should be in the first row or column and after them the new 0 inDegree numbers etc...
            so we must do 2 topoligical sorts on the rows and columns graph conditionos.
        */

        // first calculate the inDegrees and construct 2 graphs
        vector<int> inDegreeR(k + 1), inDegreeC(k + 1);
        vector<vector<int> > adjR(k + 1), adjC(k + 1);
        for(auto c: rowConditions){
            adjR[c[0]].push_back(c[1]);
            inDegreeR[c[1]]++;
        }
        for(auto c: colConditions){
            adjC[c[0]].push_back(c[1]);
            inDegreeC[c[1]]++;
        }
        
        // then run topoligical sort and get the levels for the 2 graphs
        vector<int> orderR, orderC;
        topoligicalSort(k, adjR, inDegreeR, orderR);
        topoligicalSort(k, adjC, inDegreeC, orderC);

        // check if there was a cycle
        if(orderR.size()!=k || orderC.size()!=k) return {};

        vector<int> posR(k + 1), posC(k + 1);
        for(int i = 0; i < k; i++)
            posR[orderR[i]] = i, posC[orderC[i]] = i;
        
        vector<vector<int> > ans(k, vector<int> (k));
        for(int i = 1;i <= k; i++)
            ans[posR[i]][posC[i]] = i;
        
        return ans;
    }
};