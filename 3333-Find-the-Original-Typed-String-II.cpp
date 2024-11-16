class Solution {
public:
    int mod = 1e9 + 7;

    long long add(long long a, long long b){
        return ((a % mod) + (b % mod)) % mod;
    }

    long long mul(long long a, long long b){
        return ((a % mod) * (b % mod)) % mod;
    }

    int possibleStringCount(string word, int k) {
        int n = word.size();
        vector<int> charFreq;
        for(int i = 0;i < n;){
            int j = i;
            while(j < n && word[i]==word[j])
                j++;
            charFreq.push_back(j - i);
            i = j;
        }

        long long total = 1;
        for(auto &f: charFreq) {
            total = mul(total, f--);
        }

        if(charFreq.size() >= k) return total;

        k -= charFreq.size();
        vector<long long> dp(k);
        dp[0] = 1;
        for(auto f: charFreq){
            vector<long long> pref(dp);
            for(int i = 1;i < k;i++) 
                pref[i] = add(pref[i], pref[i - 1]);
            
            for(int i = 0;i < k;i++){
                dp[i] = pref[i];
                if(i - f > 0){
                    dp[i] = add(dp[i], mod - pref[i - f - 1]);
                }
            }
        }
        long long sum = 0;
        for(auto ways: dp)
            sum = add(sum, ways);
        
        long long ans = (total + mod - sum) % mod;
        return ans;
    }
};