class Solution {
public:
    string ans = "";
    void solve(int ind, string &pattern, vector<bool> &used, string cur){
        if(ans!="") return;
        if(ind==pattern.size()){
            ans = cur;
            return;
        }
        for(int i = 1;i <= 9;i++){
            char no = i + '0';
            if(used[i] || 
            (pattern[ind]=='I' && no < cur.back()) || 
            (pattern[ind]=='D' && no > cur.back())) continue;
            
            used[i] = 1, cur += to_string(i);
            solve(ind + 1, pattern, used, cur);
            used[i] = 0, cur.pop_back();
        }
    }
    string smallestNumber(string pattern) {
        vector<bool> used(10);
        for(int i = 1;i <= 9;i++){
            used[i] = 1;
            solve(0, pattern, used, to_string(i));
            used[i] = 0;
        }
        return ans;
    }
};