class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        for(int i = 0, j = 0;i < n || j < n; i++,j++){
            while(i < n && start[i]=='_') i++;
            while(j < n && target[j]=='_')j++;

            if((start[i] != target[j]) ||
            (start[i]=='L' && i < j) ||
            (start[i]=='R' && i > j)) return false;
        }
        return true;
    }
};