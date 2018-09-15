/*
*
* Tag: DFS
* Time: O(n!)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int>> ans;
        if(nums.size() == 0)
            return ans;
        sort(nums.begin(), nums.end());
        vector<bool> vis(nums.size(), false);
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            vector<int> tmp;
            tmp.push_back(nums[i]);
            vis[i] = 1;
            dfs(tmp, ans, vis, nums, 1, n);
            vis[i] = 0;
            while(i < n - 1 && nums[i] == nums[i + 1]) ++ i;
        }
        return ans;
    }
    
    void dfs(vector<int> &tmp, vector<vector<int>> &ans, vector<bool> &vis, vector<int> nums, int dep, int tot){
        if(dep >= tot){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < tot; ++ i){
            if(vis[i])
                continue;
            tmp.push_back(nums[i]);
            vis[i] = 1;
            dfs(tmp, ans, vis, nums, dep + 1, tot);
            vis[i] = 0;
            tmp.pop_back();
            while(i < tot - 1 && nums[i] == nums[i + 1]) ++ i;
        }
    }
};
