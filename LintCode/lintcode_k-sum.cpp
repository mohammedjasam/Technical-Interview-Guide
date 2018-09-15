/*
*
* Tag: DP
* Time: O(k*target*n^3)
* Space: O(k*n*target)
*/
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int ans = 0;
        if(!A.size() || !k)
            return ans;
        int n = A.size();
        int dp[k][n][target + 1];
        memset(dp, 0, sizeof(dp));
        sort(A.begin(), A.end());
        
        for(int i = 0; i < n; ++ i){
            if(A[i] <=  target)
            dp[0][i][A[i]] = 1;
        }
        
        for(int i = 1; i < k; ++ i){
            for(int j = i; j < n; ++ j){
                if(A[j] > target)
                    break;
                for(int l = 0; l < j; ++ l){
                    for(int t = 0; t <= target; ++ t){
                        if(dp[i - 1][l][t] && t + A[j] <= target)
                            dp[i][j][t + A[j]] += dp[i - 1][l][t];
                    }
                }
            }
        }
        
        for(int i = 0; i < n; ++ i)
            ans += dp[k - 1][i][target];
        return ans;
    }
};
