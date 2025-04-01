class User {
    int userID;
    // ID, User
    unordered_set<int> followers;
public:
    User(int ID): userID(ID) {

    }
    void addFollowers(int ID){
        followers.insert(ID);
    }
    void removeFollowers(int ID){
        followers.erase(ID);
    }
    unordered_set<int>& getFollowers(){
        return followers;
    }

};

class Twitter {
public:
    map<int, User*> users;
    // vector<pair<int, int>> posts;
    unordered_map<int, deque<pair<int, int>>> tweets;  // {userId -> (timestamp, tweetId)}
    int timeCounter = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(users.find(userId)==users.end()){
            newUser(userId);
        }
        // posts.push_back({userId, tweetId});
         // 限制每個人最多只儲存最近 10 篇推文
        if (tweets[userId].size() == 10) {
            tweets[userId].pop_front();
        }
        
        tweets[userId].push_back({++timeCounter, tweetId});
    }
    // 回傳po文，從最新到最舊
    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        if(users.find(userId)==users.end()){
            newUser(userId);
            return news;
        }
        unordered_set<int>& followers = users[userId]->getFollowers();
        followers.insert(userId);
        // 遍歷所有posts
        // for (int i = 0;i<posts.size();i++){
        //     // cout<<"i "<<i;
        //     // cout<<" post "<<posts[posts.size()-1-i].second<<endl;
        //     int idx = posts[posts.size()-1-i].first;
        //     if(followers.find(idx) != followers.end()){
        //         // cout<<"?"<<endl;
        //         news.push_back(posts[posts.size()-1-i].second);
        //         if(news.size()==10){
        //             return news;
        //         }
        //     }
        // }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
 // (timestamp, tweetId)
        
        for (int followee : followers) {
            for (const auto& tweet : tweets[followee]) {
                minHeap.push(tweet);
                if (minHeap.size() > 10) {
                    minHeap.pop();
                }
            }
        }

        while (!minHeap.empty()) {
            news.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(news.begin(), news.end());  // 時間順序由新到舊
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        if(users.find(followerId)==users.end()){
            newUser(followerId);
        }
        if(users.find(followeeId)==users.end()){
            newUser(followeeId);
        }
        users[followerId]->addFollowers(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(users.find(followerId)==users.end()){
            newUser(followerId);
        }
        if(users.find(followeeId)==users.end()){
            newUser(followeeId);
        }
        users[followerId]->removeFollowers(followeeId);
    }
    void newUser(int userID){
        User *newuser = new User(userID);
        users[userID] = newuser;
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
