class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        int pref = 0, cnt = 0;
        for(int i = 0;i < n;i++){
            pref += cnt;
            ans[i] = pref;
            if(boxes[i] == '1')
                cnt++;
        }
        pref = 0, cnt = 0;
        for(int i = n - 1; i >= 0; i--){
            pref += cnt;
            ans[i] += pref;
            if(boxes[i] == '1')
                cnt++;
        }
        return ans;
    }
};