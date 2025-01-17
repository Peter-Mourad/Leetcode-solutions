class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int> o(derived.size());
        for(int i = 1;i < derived.size();i++){
            o[i] = o[i - 1] ^ derived[i - 1];
        }
        return derived.back()==o[0] ^ o.back();
    }
};