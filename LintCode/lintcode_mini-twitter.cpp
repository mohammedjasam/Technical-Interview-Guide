/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
 /*
 *
 * Tag: Sort and Implementation
 * Time: O(nlgn)
 * Space: O(n)
 */
class MiniTwitter {
public:
    MiniTwitter() {
        // initialize your data structure here.
        idx = 1;
        followship.clear();
        timeline.clear();
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        Tweet newTweet = Tweet::create(user_id, tweet_text);
        newTweet.id = idx ++;
        timeline[user_id].push_back(newTweet);
        return newTweet;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        int len = 0, totlen = timeline[user_id].size(), id = 0;
        vector<Tweet> ans, tmp;
        unordered_set<int>::iterator it = followship[user_id].begin();
        for(; it != followship[user_id].end(); ++ it){
            int uid = *it;
            totlen += timeline[uid].size();
        }
        tmp.resize(totlen);
        for(int i = 0; i < timeline[user_id].size(); ++ i, ++ id)
            tmp[id] = timeline[user_id][i];
        for(it = followship[user_id].begin(); it != followship[user_id].end(); ++ it){
            int uid = *it;
            for(int i = 0; i < timeline[uid].size(); ++ i, ++ id){
                tmp[id] = timeline[uid][i];
            }
        }
        sort(tmp.begin(), tmp.end(), mycmp);
        ans.resize(min(10, (int)tmp.size()));
        for(int i = 0; i < ans.size(); ++ i){
            ans[i] = tmp[i];
        }
        
        return ans;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        int len = min((int)timeline[user_id].size(), 10);
        vector<Tweet> ans(len);
        int id = timeline[user_id].size() - 1;
        for(int i = 0; id >= 0 && i < 10; -- id, ++ i){
            ans[i] = timeline[user_id][id];
        }
        
        return ans;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        followship[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        followship[from_user_id].erase(to_user_id);
    }

private:
    struct cmp{
        bool operator() (const Tweet &a, const Tweet &b){
            return b.id < a.id;
        }
    }mycmp;
    
private:
    unordered_map<int, unordered_set<int> > followship;
    int idx;
    unordered_map<int, vector<Tweet> > timeline;
};
