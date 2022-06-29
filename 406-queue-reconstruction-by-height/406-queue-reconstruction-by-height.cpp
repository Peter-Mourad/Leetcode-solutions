class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](vector<int> v1, vector<int> v2)->bool{
            if(v1[0] > v2[0] || (v1[0]==v2[0] && v1[1] < v2[1]))
                return true;
            return false;
        }; 
        sort(people.begin(), people.end(), comp);
        vector<vector<int> > ans;
        for(auto temp : people){
            // cout<<temp[0]<<' '<<temp[1]<<endl;
            ans.insert(ans.begin() + temp[1], temp);
        }
        return ans;
    }
};