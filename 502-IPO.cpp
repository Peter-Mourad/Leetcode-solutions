class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // every project should be represented as cost, net profit
        int n = profits.size();
        vector<pair<int,int>> projects(n);
        for(int i = 0;i < n;i++){
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());

        // add in the pq if only w >= cost
        priority_queue<int> net;
        for(int i = 0;i < n && k > 0;i++){
            while(projects[i].first > w && !net.empty() && k-- > 0){
                w += net.top();
                net.pop();
            }
            if(w < projects[i].first)
                break;
            net.push(projects[i].second);
        }
        while(!net.empty() && k-- > 0){
            w += net.top();
            net.pop();
        }
        return w;
    }
};