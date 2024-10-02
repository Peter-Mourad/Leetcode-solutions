class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arr2 = arr, rank(arr.size());
        int r = 1;
        map<int,int> hash;
        sort(arr2.begin(), arr2.end());
        for(int i = 0;i < arr2.size();){
            hash[arr2[i]] = r++;
            int j = i;
            while(j < arr2.size() && arr2[j]==arr2[i])
                j++;
            i = j;
        }
        for(int i = 0;i < arr.size();i++)
            rank[i] = hash[arr[i]];
        return rank;
    }
};