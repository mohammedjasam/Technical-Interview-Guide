/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = dp[2] = 1;
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n - i; ++ j){
                dp[i + j] = max(dp[i + j], max(dp[i]*j,i*j));
            }
        }
        return dp[n];
    }
};

/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n%3 == 1) return pow(3,((n-4)/3))*4;
        else if(n%3 == 2) return pow(3,(n/3))*2;
        else return pow(3,n/3);
    }
};
