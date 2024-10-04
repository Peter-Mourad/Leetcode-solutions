class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum = skill[0] + skill.back();
        long long ans = 0;
        for(int i = 0,j = skill.size() - 1;i < j;i++, j--){
            if(skill[i] + skill[j]!=sum)return -1;
            ans += skill[i] * skill[j];
        }
        return ans;
    }
};