class Solution {
public:
    bool isDigit(char a){
        return a >= '0' && a <= '9';
    }
    bool isSign(char a){
        return a=='+' || a=='-';
    }
    bool validateNumber(string &num){
        if(num.size()==1 && !isDigit(num[0])) return false;
        int i = isSign(num[0]);
        if(i==1 && num[i]=='.' && num.size()==2) return false;
        for(;i < num.size();i++){
            if(isDigit(num[i]))
                continue;
            else if(num[i]=='.'){
                for(int j = i + 1;j < num.size();j++)   
                    if(!isDigit(num[j])) return false;
                return true;
            }
            else return false;
        }
        return true;
    }
    bool validateInteger(string num){
        int i = (num[0]=='+' || num[0]=='-');
        if(i==1 && num.size()==1) return false;
        for(;i < num.size();i++){
            if(!isDigit(num[i]))
                return false;
        }
        return true;
    }
    bool isNumber(string s) {
        int indE = s.size();
        if(s.find('e') != string::npos)
            indE = s.find('e');
        if(s.find('E') != string::npos)
            indE = s.find('E');
        string number = s.substr(0, indE), 
        exponent = indE==s.size() ? "" : s.substr(indE + 1, s.size());
        cout<<number<<' '<<exponent<<endl;
        cout<<validateNumber(number)<<" "<<validateInteger(exponent)<<endl;
        if(indE < s.size() && exponent=="" || !indE)
            return false;
        return validateInteger(exponent) && validateNumber(number);
    }
};