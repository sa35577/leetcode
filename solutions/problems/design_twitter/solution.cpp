class Twitter {
public:
    map<int,set<int>> userFollow; //what users a person follows
    map<int,vector<pair<int,int>>> tweets; //tweets that a user made, stored as pair(time,id)
    int cnt; //count for number of tweets so far
    Twitter() {
        cnt = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        if (tweets.find(userId) == tweets.end()) {
            vector<pair<int,int>> v;
            v.push_back({cnt++,tweetId});
            tweets[userId] = v;
        }
        else {
            tweets[userId].push_back({cnt++,tweetId});
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        //if (userFollow.find(userId) == userFollow.end()) return res;
        //cout << userId << "is the current id\n";
        map<int,pair<int,int>> mp; // time -> {author,index in tweets[author] array}
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq; //pair<time,tweetid>
        for (auto it = userFollow[userId].begin(); it != userFollow[userId].end(); it++) {
            int author = *it;
            if (tweets.find(author) != tweets.end() && tweets[author].size() > 0) {
                mp[tweets[author].back().first] = {author,tweets[author].size()-1};
                pq.push({tweets[author].back().first,tweets[author].back().second});
            }
        }
        //adding self
        if (tweets.find(userId) != tweets.end() && tweets[userId].size() > 0) {
            mp[tweets[userId].back().first] = {userId,tweets[userId].size()-1};
            pq.push({tweets[userId].back().first,tweets[userId].back().second});
            //cout << tweets[userId].back().first << "AAA" << endl;
        }
        //cout << pq.size() << endl;
        int cnt = 0;
        while (cnt < 10 && !pq.empty()) {
            pair<int, int> curTweet = pq.top();
            int tweetTime = curTweet.first, tweetId = curTweet.second;
            res.push_back(tweetId);
            pq.pop();
            pair<int, int> nextTweetData = mp[tweetTime];
            mp.erase(tweetTime);
            int nextTweetIdx = nextTweetData.second-1;
            int tweetAuthor = nextTweetData.first;
            if (nextTweetIdx >= 0) {
                mp[tweets[tweetAuthor][nextTweetIdx].first] = {tweetAuthor,nextTweetIdx};
                pq.push({tweets[tweetAuthor][nextTweetIdx].first,tweets[tweetAuthor][nextTweetIdx].second});
            }
            cnt++;
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if (userFollow.find(followerId) == userFollow.end()) {
            set<int> follow;
            follow.insert(followeeId);
            userFollow[followerId] = follow;
        }
        else {
            userFollow[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userFollow.find(followerId) != userFollow.end()) {
            userFollow[followerId].erase(followeeId);
        }
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