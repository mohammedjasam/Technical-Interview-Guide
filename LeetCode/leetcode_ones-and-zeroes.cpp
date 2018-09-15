/*
*
* Tag: DP
* Time:O(Nmn)
* Space: O(mn)
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans = 0;
        if(strs.size() == 0 || (m == 0 && n == 0)){
            return ans;
        }
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        pair<int,int> digitnum;
        int nxt_i = 0, nxt_j = 0;
        for(int l = 0; l < strs.size(); ++ l){
            getOneZeroNum(strs[l], digitnum);
            for(int i = m; i >= digitnum.first; -- i){
                for(int j = n; j >= digitnum.second; -- j){
                    nxt_i = i - digitnum.first, nxt_j = j - digitnum.second;
                    if(dp[nxt_i][nxt_j] > 0 || (nxt_i == 0 && nxt_j == 0)){
                        dp[i][j] = max(dp[i][j], dp[nxt_i][nxt_j] + 1);
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        
        return ans;
    }
private:
    void getOneZeroNum(string strs, pair<int,int> &digitnum){
        digitnum.first  = digitnum.second = 0;
        for(int i = 0; i < strs.size(); ++ i){
            if(strs[i] == '0') {
                ++ digitnum.first;
            } else {
                ++ digitnum.second;
            }
        }
    }
};
