/*
*
* Tag: Data Structure
* Time: O(nlogn)
* Space: O(n)
*/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0)
            return ans;
        map<int,int> rank;
        ans.resize(nums.size());
        int rank_val = nums.size();
        for(int i = 0; i < nums.size(); ++ i){
            rank[nums[i]] = 0;
        }
        for(auto it = rank.begin(); it != rank.end(); ++ it, -- rank_val){
            it->second = rank_val;
        }
        for(int i = 0; i < nums.size(); ++ i){
            ans[i] = getRank(rank[nums[i]]);
        }
        return ans;
    }
private:
    inline string getRank(int key){
        if(key > 3)
            return to_string(key);
        else if(key == 3)
            return "Bronze Medal";
        else if(key == 2)
            return "Silver Medal";
        else
            return "Gold Medal";
    }
};
