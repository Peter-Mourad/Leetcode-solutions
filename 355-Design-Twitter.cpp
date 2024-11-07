class Twitter {
public:
    vector<unordered_set<int> > following; // tweetId, time
    vector<vector<pair<int,int> >> tweets;
    int time;
    Twitter() {
        following.resize(501);
        tweets.resize(501);
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time++});
    }
    
    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);
        vector<int> res;
        // put all followees recent tweet's time and followeeId and tweetId in max heap
        priority_queue<pair<int,pair<int,int> > > recent_tweets;
        for(auto followeeId: following[userId]){
            if(tweets[followeeId].empty())
                continue;
            
            recent_tweets.push({
                tweets[followeeId].back().second, {
                    followeeId, 
                    tweets[followeeId].back().first
                }
            });
        }

        while(res.size() < 10 && !recent_tweets.empty()){
            int followeeId = recent_tweets.top().second.first;
            int tweetId = recent_tweets.top().second.second;
            int tweet_time = recent_tweets.top().first;

            res.push_back(tweetId);
            recent_tweets.pop();

            // get next recent tweet from the same followee and add it to recent_tweets
            for(int i = tweets[followeeId].size() - 1; i >= 0; i--){
                if(tweets[followeeId][i].second < tweet_time){
                    recent_tweets.push({tweets[followeeId][i].second, {followeeId, tweets[followeeId][i].first}});
                    break;
                }
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */