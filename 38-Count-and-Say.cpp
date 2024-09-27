class Solution {
public:
    string RLE(string &cur){
        string res = "";
        for(int i = 0;i < cur.size();){
            int j = i;
            while(j < cur.size() && cur[i]==cur[j])
                j++;
            res += to_string(j - i) + cur[i];
            i = j;
        }
        return res;
    }

    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2;i <= n;i++)
            ans = RLE(ans);
        
        return ans;
    }
};