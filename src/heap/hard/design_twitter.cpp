// statement-  Create simplified version of Twitter. Users should be able to post tweets, follow or unfollow r users, & view 10 most recent tweets inir news feed


//(optimal)

unordered_map<int, vector<pair<int, int>>> tweets; // Stores tweets of each user as vector of (timestamp, tweetId)
unordered_map<int, unordered_set<int>> following; // Stores set of followees for each user
int time; // Global time counter to sort tweets

// Constructor to initialize time counter
Twitter(){
    time = 0;
}

// Function to post a tweet, t.c- O(1) , s.c- O(1)
void postTweet(int userId, int tweetId){
    tweets[userId].push_back({time++, tweetId}); // Add tweet with curr timestamp to user's tweet list
}

// Function to get 10 most recent tweets in news feed, t.c- O(klogk) , s.c- O(k)
vector<int> getNewsFeed(int userId){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap to store tweets based on timestamp

    // Insert user's own tweets
    for (auto &t : tweets[userId]){
        pq.push(t);
        if (pq.size() > 10) pq.pop(); // Keep heap size max 10
    }

    // Insert tweets from users being followed
    for (int followee : following[userId]){
        for (auto &t : tweets[followee]){
            pq.push(t);
            if (pq.size() > 10) pq.pop();
        }
    }

    // Extract tweets from heap in reverse order
    vector<int> res;
    while (!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

// Function to follow any user, t.c- O(1) , s.c- O(1)
void follow(int followerId, int followeeId){
    following[followerId].insert(followeeId);
}

// Function to unfollow any user, t.c- O(1) , s.c- O(1)
void unfollow(int followerId, int followeeId){
    following[followerId].erase(followeeId);
}