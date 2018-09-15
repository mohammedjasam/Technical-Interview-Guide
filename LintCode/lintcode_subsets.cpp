/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code her
    	vector<vector<int>> ans(1);
        if(nums.size() == 0)
            return ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            vector<int> tmpans;
            tmpans.push_back(nums[i]);
            ans.push_back(tmpans);
            dfs(tmpans, ans, nums, i);
            while(i + 1 < n && nums[i] == nums[i + 1]) ++ i;
        }
        return ans;
    }
    
    void dfs(vector<int> &tmpans, vector<vector<int>> &ans, vector<int> S, int id){
        int n = S.size();
        for(int i = id + 1; i < n; ++ i){
            tmpans.push_back(S[i]);
            ans.push_back(tmpans);
            dfs(tmpans, ans, S, i);
            while(i + 1 < n && S[i] == S[i + 1]) ++ i;
            tmpans.pop_back();
        }
    }
};
