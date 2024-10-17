class Solution {
public:
    int maximumSwap(int num) {
        string x = to_string(num);
        for(int i = 0;i < x.size() - 1;i++){
            pair<char,int> mx = {x[i], i};
            for(int j = i + 1;j < x.size();j++){
                if(x[j] >= mx.first)
                    mx = {x[j], j};
            }
            if(mx.first > x[i]){
                swap(x[i], x[mx.second]);
                break;
            }
        }
        int ans = 0;
        for(int i = x.size() - 1, pow = 1; ~i; i--, pow *= 10)
            ans += (x[i] - '0') * pow;
        return ans;
    }
};