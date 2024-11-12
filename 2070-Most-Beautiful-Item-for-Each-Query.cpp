class Solution {
public:
    static bool comp(vector<int> &it1, vector<int> &it2){
        if(it1[0] < it2[0] || (it1[0]==it2[0] && it1[1] > it2[1]))
            return true;
        return false;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end(), comp);
        vector<pair<int, int> > sortedItems;
        for(int i = 0; i < n; i++){
            if(!sortedItems.empty() && items[i][0]==sortedItems.back().first)   continue;
            sortedItems.push_back({items[i][0], items[i][1]});
        }
        vector<int> mx(sortedItems.size() + 1);
        for(int i = 0; i < sortedItems.size(); i++){
            mx[i + 1] = max(mx[i], sortedItems[i].second);
        }

        vector<int> ans;
        for(auto q: queries){
            int ind = upper_bound(sortedItems.begin(), sortedItems.end(), make_pair(q, INT_MAX)) - sortedItems.begin();
            ans.push_back(mx[ind]);
        }
        return ans;
    }
};