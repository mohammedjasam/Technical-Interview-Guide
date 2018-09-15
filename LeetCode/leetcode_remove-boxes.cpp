/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n^3)
*/
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp, 0, sizeof(dp));
        return dfs(boxes, 0, n - 1, 0);
    }
    
private:
    int dfs(vector<int>& boxes, int l, int r, int k){
        if(l > r)
            return 0;
        if(dp[l][r][k] != 0)
            return dp[l][r][k];
        while(r > l && boxes[r] == boxes[r - 1]){
            --r;
            ++ k;
        }
        dp[l][r][k] = dfs(boxes, l, r - 1, 0) + (k + 1)*(k + 1);
        for(int i = l; i < r; ++ i){
            if(boxes[i] == boxes[r]){
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
private:
    int dp[100][100][100];
};
