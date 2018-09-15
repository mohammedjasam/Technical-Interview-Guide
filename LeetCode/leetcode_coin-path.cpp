/*
*
* Tag: DP
* Time: O(nb)
* Space: O(n)
*/
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        vector<int> ans;
        if(A.size() == 0 || B == 0 || A.back() < 0){
            return ans;
        }
        
        int n = A.size();
        vector<pair<int,int>> dp(n);
        dp[n - 1].first = A[n - 1], dp[n - 1].second = -1;
        
        for(int i = n - 2; i >= 0; -- i){
            dp[i].first = INT_MAX;
            if(A[i] < 0){
                continue;
            }
            
            for(int j = i + 1; j <= min(i + B, n - 1); ++ j){
                if(dp[j].first == INT_MAX){
                    continue;
                }
                
                if(dp[j].first + A[i] < dp[i].first){
                    dp[i].first = dp[j].first + A[i];
                    dp[i].second = j;
                }
                
            }            
        }
        
        if(dp[0].first == INT_MAX){
            return ans;
        }
        
        for(int i = 0; i != -1; i = dp[i].second){
            ans.push_back(i + 1);
        }
        
        return ans;
    }
};
