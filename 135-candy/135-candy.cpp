#define ll long long
class Solution {
public:
    
    int candy(vector<int>& ratings) {
        ll ans = 0, inc = 0, dec = 0;
        int n = ratings.size();
        ratings.push_back(ratings.back());
        for(int i = 0;i < n;i++){
            // increasing sequence
            if(ratings[i] < ratings[i + 1]){
                int in = i;
                while(in < n && ratings[in] < ratings[in + 1])
                    in++;
                
                int tot = in - i + 1;
                // add the cost of the sequence
                ans+=(tot * (tot + 1) / 2);
                // minus the overlapping cost if exists
                if(dec)  
                    ans--;
                
                dec = 0,inc = tot;
                i = in - 1;
            }
            
            //decreasing
            else if(ratings[i] > ratings[i + 1]){
                int in = i;
                while(in < n && ratings[in] > ratings[in + 1])
                    in++;
                
                // add the cost of the sequence
                ll tot = in - i + 1;
                ans += tot * (tot + 1) / 2;
                // minus the overlapping cost if exists
                if(inc)
                    ans-=min(inc,tot);
                         
                i = in - 1;
                inc = 0, dec = tot;
            }
            else{
                int in = i;
                while(in < n && ratings[in] == ratings[in + 1])
                    in++;
                
                // add the cost of the sequence which is between
                // two increasing or decreasing sequences as 1's
                int tot = in - i + 1;
                ans += max(0,tot - 2);
                if(!inc && !dec)
                    ans++;
                i = in - 1;
                inc = 0,dec = 0;
            }
        }
        return ans;
    }
};