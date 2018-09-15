/*
*
* Tag: DP
* Time: O(kn^2)
* Space: O(kn+n^2)
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        double ans = 0;
        if(A.size() == 0){
            return ans;
        }
        
        int num = A.size();
        vector<vector<double>> avgOfSubArray(num, vector<double>(num));
        for(int i = 0; i < num; ++ i){
            int sum = 0;
            for(int j = i; j < num; ++ j){
                sum += A[j];
                avgOfSubArray[i][j] = (double)sum/(double)(j - i + 1);
            }
        }
        
        vector<vector<double>> dp(num, vector<double>(K, -1.0));
        for(int i = 0; i < num; ++ i){
            dp[i][0] = avgOfSubArray[0][i];
            for(int j = 1; j <= i; ++ j){
                for(int k = 1; k < K && k <= j; ++ k){
                    if(dp[j - 1][k - 1] < 0){
                        break;
                    }
                    
                    dp[i][k] = max(dp[i][k], dp[j - 1][k - 1] + avgOfSubArray[j][i]);
                }
            }
        }
        
        for(int i = 0; i < K; ++ i){
            ans = max(ans, dp[num - 1][i]);
        }
        
        return ans;
    }
};
