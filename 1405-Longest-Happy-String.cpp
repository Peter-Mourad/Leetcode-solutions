class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int,char>> l = {{a,'a'}, {b,'b'}, {c,'c'}};
        string ans = "";
        while(true){
            sort(l.rbegin(), l.rend());
            int p = 0;
            if(ans.size() > 1 && ans.back()==l[p].second && ans[ans.size() - 2]==l[p].second)
                p++;
            if(!l[p].first)break;
            l[p].first--;
            ans += l[p].second;
        }
        return ans;
    }
};