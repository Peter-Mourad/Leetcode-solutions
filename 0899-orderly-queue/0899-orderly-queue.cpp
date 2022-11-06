class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            string ans = s;
            for(int i = 1;i<=s.size();i++){
                s+=s[0];
                s.erase(0,1);
                if(s < ans)
                    ans = s;
            }
            return ans;
        }
        else{
            sort(s.begin(),s.end());
            return s;
        }
    }
};