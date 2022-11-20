#define ll long long
class Solution {
public:
    int string_to_int(string &a){
        ll res = 0, pow = 1;
        for(int i = a.size() - 1;i>=0;i--,pow*=10){
            res+=pow * (a[i] - '0');
        }
        return res;
    }
    string s;
    int eval(int i,int j){
        int neg = 1;
        string temp = "";
        ll ans = 0;
        for(;i <= j;i++){
            char a = s[i];
            if(a=='('){
                int open = 1,j = i + 1;
                for(;j < s.size() && open;j++){
                    if(s[j]==')')
                        open--;
                    if(s[j]=='(')
                        open++;
                }
                ans += neg * eval(i + 1,j - 1);
                i = j - 1;
                continue;    
            }
            if(a==')' || a==' ')continue;
            if(a=='+'){
                ans += neg * string_to_int(temp);
                temp = "";
                neg = 1;
            }
            else if(a=='-'){
                if(temp!=""){
                    ans += neg * string_to_int(temp);
                    temp = "";
                }
                neg = -1;
            }
            else
                temp+=a;
        }
        if(temp!="")
            ans += neg * string_to_int(temp);
        return ans;
    }
    int calculate(string x) {
        s = x;
        return eval(0,x.size() - 1);
    }
};