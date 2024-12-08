class Solution {
public:
    static bool comp(vector<int> &e1, vector<int> &e2){
        return (e1[0] < e2[0] || 
        (e1[0]==e2[0] && e1[1] < e2[1]));
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), comp);
        vector<int> mxSuff(n + 1, INT_MIN), open(n);
        for(int i = n - 1; ~i; i--){
            mxSuff[i] = max(mxSuff[i + 1], events[i][2]);
            open[i] = events[i][0];
        }

        // to keep track of previous events and see the max value
        // of which that are finished before event[i]
        priority_queue<pair<int,int> , vector<pair<int, int>>, greater<> > pq;
        int mxPrev = INT_MIN, ans = INT_MIN;
        for(int i = 0;i < n;i++){
            ans = max(ans, events[i][2]);
            while(!pq.empty() && pq.top().first < events[i][0]){
                mxPrev = max(mxPrev, pq.top().second);
                pq.pop();
            }
            ans = max(ans, events[i][2] + mxPrev);
            int l = upper_bound(open.begin(), open.end(), events[i][1]) - open.begin();
            ans = max(ans, events[i][2] + mxSuff[l]);
            pq.push({events[i][1], events[i][2]});
        }
        return ans;
    }
};