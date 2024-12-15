class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        double ans = 0;
        for(int i = 0;i < n;i++){
            double before = classes[i][0] * 1.0 / classes[i][1];
            classes[i][0]++, classes[i][1]++;
            double after = classes[i][0] * 1.0 / classes[i][1];
            pq.push({after - before, i});
            classes[i][0]--, classes[i][1]--;
            ans += before;
        }
        double eps = 1e-6;
        while(extraStudents-- && !pq.empty()){
            double add = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if(add <= eps) break;
            ans += add;
            classes[i][0] ++, classes[i][1] ++;
            double before = classes[i][0] * 1.0 / classes[i][1]; 
            classes[i][0] ++, classes[i][1] ++;
            double after = classes[i][0] * 1.0 / classes[i][1];
            pq.push({after - before, i});
            classes[i][0]--, classes[i][1]--;
        }
        return ans / n;
    }
};