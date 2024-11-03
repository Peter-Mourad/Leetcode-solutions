class Solution {
public:
    int longestPrefixSuffix(string &x, string &y) {
        string concat = x + "#" + y;
        int n = concat.size();
        vector<int> lps(n, 0);
        int length = 0;
        for(int i = 1; i < n;){
            if (concat[i] == concat[length]) {
                length++;
                lps[i++] = length;
            } 
            else 
                (length) ? length = lps[length - 1] : lps[i++] = 0;
        }
        return lps[n - 1];
    }

    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;

        int res = longestPrefixSuffix(s, goal);
        for(int i = res, j = 0; i < s.size(); i++, j++){
            if(s[i] != goal[j])
                return false;
        }
        return true;
    }
};