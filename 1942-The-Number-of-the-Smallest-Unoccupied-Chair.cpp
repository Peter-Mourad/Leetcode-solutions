class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        set<int> empty;
        for(int i = 0;i < n;i++) empty.insert(i);

        vector<pair<int, pair<int,int>> > friends(n);
        for(int i = 0;i < n;i++){
            friends[i] = {times[i][0], {times[i][1], i}};
        }
        sort(friends.begin(), friends.end());

        set<pair<int,int>> leaves;
        vector<int> ans(n);
        for(int i = 0;i < n;i++){
            pair<int,int> interval = {friends[i].first, friends[i].second.first};
            while(!leaves.empty()){
                auto leave = *leaves.begin();
                if(leave.first <= interval.first){
                    empty.insert(leave.second);
                    leaves.erase(leave);
                } 
                else break;
            }
            int seat = *empty.begin();
            empty.erase(empty.begin());
            leaves.insert({interval.second, seat});
            ans[friends[i].second.second] = seat;
        }
        return ans[targetFriend];
    }
};