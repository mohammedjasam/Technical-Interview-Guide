/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        int sum = 0, n = nums.size();
        dfs(sum, ans, nums, 0, n, S);
        return ans;
    }
private:
    void dfs(int sum, int &ans, vector<int> &nums, int dep, int n, int S){
        if(dep >= n){
            if(sum == S)
                ++ ans;
            return ;
        }
        dfs(sum - nums[dep], ans, nums, dep + 1, n, S);
        dfs(sum + nums[dep], ans, nums, dep + 1, n, S);
    }
};

/*
*
* Tag: DP
* Time: O(2^n)
* Space: O(2^n)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        unordered_map<int,int> pre, cur;
        int n = nums.size();
        ++ pre[nums[0]]; ++ cur[nums[0]]; 
        ++ pre[-nums[0]]; ++ cur[-nums[0]];
        for(int i = 1; i < n; ++ i){
            cur.clear();
            for(unordered_map<int,int>::iterator it = pre.begin(); it != pre.end(); ++ it){
                cur[(it->first + nums[i])] += it->second;
                cur[(it->first - nums[i])] += it->second;
            }
            pre = cur;
        }
        ans = (cur.count(S) != 0?cur[S]:0);
        return ans;
    }
};

