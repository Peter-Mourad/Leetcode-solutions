class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> q;
        int l = 0;
        auto comp = [](vector<int>p1,vector<int> p2) ->bool{
            return p1[1] < p2[1];  
        };
        sort(courses.begin(), courses.end(), comp);
        for(int i = 0;i < courses.size();i++){
            int need = courses[i][0],mx = courses[i][1];
            q.push(need);
            l+=need;
            if(l > mx){
                l-=q.top();
                q.pop();
            }
        }
        return q.size();
    }
};