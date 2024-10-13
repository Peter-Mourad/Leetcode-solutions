class Solution {
public:
    string stringToBinary(string a){
        int ans = 0;
        for(int i = a.size() - 1, pow = 1; ~i; i--, pow*=10)
            ans += (a[i] - '0') * pow;
        string binary = "";
        while(ans){
            binary += (ans & 1) ? '1' : '0';
            ans >>= 1;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }

    string convertDateToBinary(string date) {
        string day = stringToBinary(date.substr(8,2)), month = stringToBinary(date.substr(5,2)), year = stringToBinary(date.substr(0,4));
        return year + '-' + month + '-' + day;
    }
};