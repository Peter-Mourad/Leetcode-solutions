class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> a,b;
        vector<int> ans;
        int cnt = 0;
        for(int i = 0;i < A.size();i++){
            if(A[i]==B[i]){
                cnt++;
                ans.push_back(cnt);
                continue;
            }
            if(!a.count(B[i]))
                b.insert(B[i]);
            else {
                cnt++;
                a.erase(B[i]);
            }

            if(!b.count(A[i]))
                a.insert(A[i]);
            else{
                cnt++;
                b.erase(A[i]);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};