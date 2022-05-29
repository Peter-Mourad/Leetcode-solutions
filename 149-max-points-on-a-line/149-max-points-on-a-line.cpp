class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(),ans = 0;
        for(int i = 0;i < n;i++){
            int mx = 0,overlapping = 0,vertical = 0;
            map<double,int> mp;
            for(int j = i + 1;j < n;j++){
                if(points[i][0]==points[j][0] && 
                  points[i][1]==points[j][1])overlapping++;
                else if(points[i][0]==points[j][0])vertical++;
                else{
                    double slope = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                    // cout<<slope<<' ';
                    mp[slope]++;
                }
            }
            for(auto p : mp)
                mx = max(mx,p.second);
            ans = max(ans,max(mx + overlapping,vertical));
            // cout<<endl;
        }
        return ans + 1;
    }
};