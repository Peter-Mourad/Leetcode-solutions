class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        multiset<int> s;
        for(auto a: nums) s.insert(a);
        long long ans = 0;
        while(k-- && !s.empty()){
            auto p = s.end();
            int no = *(--p);
            ans += no;
            s.erase(p);
            no += 2;
            if(no / 3)
                s.insert(no / 3);
        }   
        return ans;
    }
};