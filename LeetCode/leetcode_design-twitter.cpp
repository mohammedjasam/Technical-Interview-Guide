/*
*
* Tag: HashMap & Heap
* Time: getNewsFeed: O(nlgn); Add/Remove Followers: O(1)
* Space: O(n)
*/
class Twitter {
private:
    struct tweet{
        int uid, tid, ts;
        tweet(int ui, int ti, int t){
            uid = ui, tid = ti, ts = t;
        }
    };
public:
    /** Initialize your data structure here. */
    Twitter() {
        followship.clear();
        posttweets.clear();
        timestamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet twt(userId, tweetId, timestamp ++);
        posttweets[userId].push_front(twt);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<list<tweet>::iterator, vector<list<tweet>::iterator>, cmp > pq;
        list<tweet>::iterator cur;
        int cnt = 0, uid = 0;
        if(posttweets[userId].size() > 0)
            pq.push(posttweets[userId].begin());
        for(unordered_set<int>::iterator it = followship[userId].begin(); it != followship[userId].end(); ++ it){
            if(posttweets[*it].size() > 0)
                pq.push(posttweets[*it].begin());
        }
        while(!pq.empty() && cnt < 10){
            cur = pq.top();
            pq.pop();
            ans.push_back(cur->tid);
            uid = cur->uid;
            ++ cnt;
            ++ cur;
            if(cnt <  10 && cur != posttweets[uid].end()){
                pq.push(cur);
            }
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return ;
        followship[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followship[followerId].erase(followeeId);
    }
private:
    struct cmp{
	   bool operator() (const list<tweet>::iterator a, const list<tweet>::iterator b){
	        return a->ts < b->ts; 
	   }
	}cmpfunc;
private:
    unordered_map<int,unordered_set<int> > followship;
    unordered_map<int,list<tweet> > posttweets;
    int timestamp;
};
