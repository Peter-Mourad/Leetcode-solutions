class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> o(n);
        for(int i = 1;i < n;i++){
            o[i] = o[i - 1] ^ derived[i - 1];
        }
        return derived[n - 1]==o[0] ^ o[n - 1];
    }
};