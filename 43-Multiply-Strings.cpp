class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1==\0\ || num2==\0\)return \0\;
        int n = num1.size(), m = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> pos(n + m + 2);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pos[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int rem = 0;
        string ans=\\;
        for(int i = 0;i < pos.size();i++){
            pos[i] += rem;
            rem = 0;
            if(pos[i] > 9){
                rem = pos[i] / 10;
                pos[i] %= 10;
            }
            ans += char(pos[i] + '0');
        }

        while(ans.back()=='0')ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};