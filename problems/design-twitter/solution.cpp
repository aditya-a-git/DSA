class Twitter {
    unordered_map<int, unordered_set<int>> follows;
    vector<pair<int, int>> tweets;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int n = tweets.size();

        for (int i = n - 1; i >= 0; i--) {
            auto [user, tweet] = tweets[i];
            auto it = follows.find(userId);

            if (user == userId || (it != follows.end() &&
                                   it->second.find(user) != it->second.end())) {
                feed.push_back(tweet);
            }

            if (feed.size() == 10) {
                break;
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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