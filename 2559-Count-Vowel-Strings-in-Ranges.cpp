class Solution {
public:
    bool isVowel(char a){
        return (a=='a' || a=='e' || a=='o' || a=='i' || a=='u');
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> is_vowel(n), pref(n + 1);
        for(int i = 0;i < n;i++){
            is_vowel[i] = (isVowel(words[i][0]) & isVowel(words[i].back()));
            pref[i + 1] = pref[i] + is_vowel[i];
        }
        vector<int> ans(queries.size());
        for(int i = 0;i < queries.size();i++){
            ans[i] = pref[queries[i][1] + 1] - pref[queries[i][0]];
        }
        return ans;
    }
};