class Solution {
public:
    void mapping(map<string, string> &mp){
        mp["1"] = "One";
        mp["2"] = "Two";
        mp["3"] = "Three";
        mp["4"] = "Four";
        mp["5"] = "Five";
        mp["6"] = "Six";
        mp["7"] = "Seven";
        mp["8"] = "Eight";
        mp["9"] = "Nine";
        mp["10"] = "Ten";
        mp["11"] = "Eleven";
        mp["12"] = "Twelve";
        mp["13"] = "Thirteen";
        mp["14"] = "Fourteen";
        mp["15"] = "Fifteen";
        mp["16"] = "Sixteen";
        mp["17"] = "Seventeen";
        mp["18"] = "Eighteen";
        mp["19"] = "Nineteen";
        for(int i = 20;i < 30;i++)
            mp[to_string(i)] = "Twenty";
        for(int i = 30;i < 40;i++)
            mp[to_string(i)] = "Thirty";
        for(int i = 40;i < 50;i++)
            mp[to_string(i)] = "Forty";
        for(int i = 50;i < 60;i++)
            mp[to_string(i)] = "Fifty";
        for(int i = 60;i < 70;i++)
            mp[to_string(i)] = "Sixty";
        for(int i = 70;i < 80;i++)
            mp[to_string(i)] = "Seventy";
        for(int i = 80;i < 90;i++)
            mp[to_string(i)] = "Eighty";
        for(int i = 90;i < 100;i++)
            mp[to_string(i)] = "Ninety";
    }

    string three_digit_conversion(string str, map<string, string> &mp){
        string ans = "";
        if(str[0]!='0')
            ans += mp[str.substr(0,1)] + " Hundred";
        if((str[1]!='0' || str[2]!='0') && ans!="")
            ans += ' ';
        if(str[1]=='0' && str[2]!='0')
            ans += mp[str.substr(2,1)];
        else if(str[1] != '0'){
            // > 9
            ans += mp[str.substr(1,2)];
            // if > 19
            if(str[1] > '1' && str[2]!='0')
                ans += " " + mp[str.substr(2,1)];
        }
        return ans;
    }

    string numberToWords(int num) {
        string no = to_string(num), ans = "";
        no = string(10 - no.size(), '0') + no;
        map<string, string> mp;
        mapping(mp);
        if(no[0]!='0')
            ans += mp[no.substr(0,1)] + " Billion ";
        string millions = three_digit_conversion(no.substr(1,3), mp);
        string thousands = three_digit_conversion(no.substr(4,3), mp);
        string hundreds = three_digit_conversion(no.substr(7,3), mp);
        if(millions!="")
            ans += millions + " Million ";
        if(thousands!="")
            ans += thousands + " Thousand ";
        if(hundreds!="")
            ans += hundreds;
        
        if(ans=="")
            ans = "Zero";
        int i = 0,j = ans.size() - 1;
        while(ans[i]==' ')
            i++;
        while(ans[j]==' ')
            j--;
        return ans.substr(i,j - i + 1);
    }
};