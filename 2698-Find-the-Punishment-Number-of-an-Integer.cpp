class Solution {
public:
    bool check(int i, string no, int n, int sum){
        if(i==no.size()) return sum==n;
        if(sum > n) return 0;
        bool res = 0;
        string temp = "";
        for(int j = i;j < no.size();j++){
            temp += no[j];
            res |= check(j + 1, no , n, sum + stoi(temp));
        }
        return res;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(check(0, to_string(i * i), i, 0))
                ans += i * i;
        }
        return ans;
    }
};