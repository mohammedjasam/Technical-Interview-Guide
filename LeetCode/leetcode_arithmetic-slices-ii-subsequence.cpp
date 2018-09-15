/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        if(A.size() == 0)
            return ans;
        vector<unordered_map<long long,int>> dp(A.size());
        long long dif = 0;
        for(int i = 1; i < A.size(); ++ i){
            for(int j = i - 1; j >= 0; -- j){
                dif = (long long)A[i] - (long long)A[j];
                if(dp[j].count(dif) > 0){
                    ans += dp[j][dif];
                    dp[i][dif] += dp[j][dif];
                }
                ++ dp[i][dif];
            }
        }
        return ans;
    }
};
