class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto a: nums) q.push(a);
        long long ans = 0;
        while(k-- && !q.empty()){
            int a = q.top();
            q.pop();
            ans += a;
            if((a + 2) / 3)
                q.push((a + 2) / 3);
        }   
        return ans;
    }
};