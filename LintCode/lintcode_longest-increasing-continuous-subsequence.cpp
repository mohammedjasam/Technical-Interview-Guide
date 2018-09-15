/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int ans = 0;
        if(!A.size())
            return ans;
        int n = A.size();
        vector<int> dp(n), dp_rev(n);
        dp[0] = 1;
        ans = 1;
        for(int i = 1; i < n; ++ i){
            if(A[i] > A[i - 1])
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = 1;
            ans = max(ans, dp[i]);
        }
        dp_rev[n - 1] = 1;
        for(int i = n - 2; i >= 0; -- i){
            if(A[i] > A[i + 1])
                dp_rev[i] = dp_rev[i + 1] + 1;
            else
                dp_rev[i] = 1;
            ans = max(ans, dp_rev[i]);
        }
        return ans;
    }
};
