#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<string, null_type,less<string>, rb_tree_tag,tree_order_statistics_node_update>
class Solution {
public:
    ordered_set res;
    void solve(int i, int &n, int &k, string &cur){
        if(res.size() == k) return;
        if(i==n){
            res.insert(cur);
            return;
        }
        for(char ch = 'a';ch<='c';ch++){
            if(cur=="" || cur.back()!=ch){
                cur += ch;
                solve(i + 1, n, k, cur);
                cur.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string cur = "";
        solve(0, n, k, cur);
        return (res.size() < k ? "" : *(res.find_by_order(k - 1)));
    }
};