class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string temp, prev = "", first;
        while(ss >> temp){
            if(prev!="" && temp[0]!=prev.back()) return false;
            if(prev=="")first = temp;
            prev = temp;
        }
        return prev.back()==first[0];
    }
};