#define all(s) s.begin(), s.end()
class Solution {
public:
    int solve(int i, set<char> s, vector<string>& arr){
        if(i==arr.size()){
            return s.size();
        }
        bool can_take = 1;
        set<char> temp;
        for(auto a : arr[i]){
            if(s.find(a)!=s.end() || temp.find(a)!=temp.end()){
                can_take = 0;
                break;
            }
            temp.insert(a);
        }
        int ans = 0;
        if(can_take){
            s.insert(all(temp));
            ans = solve(i + 1, s, arr);
            for(auto a : temp)
                s.erase(a);
        }
        ans = max(ans, solve(i + 1, s, arr));
        return ans;
    }
    int maxLength(vector<string>& arr) {
        set<char> s;
        return solve(0, s, arr);
    }
};