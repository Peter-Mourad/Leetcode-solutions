class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int j = -1, diff = 0;
        for(int i = 0;i < s1.size() && diff <= 2;i++){
            if(s1[i] != s2[i]){
                if(~j) swap(s1[i], s1[j]);
                else j = i;
                diff++;
            }
        }
        return diff <= 2 && s1==s2;
    }
};