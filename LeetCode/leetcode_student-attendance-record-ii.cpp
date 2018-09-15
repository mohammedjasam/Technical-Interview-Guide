/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    const int MOD = 1000000007;
public:
    int checkRecord(int n) {
        int ans = 0;
        if(n == 0)
            return ans;
        vector<int> pre(7), cur(7);
        pre[0] = pre[3] = pre[6] = 1;
        cur = pre;
        for(int i = 1; i < n; ++ i){
            
            for(int j = 0; j < 7; ++ j)
                cur[j] = 0;
            
            //End with A
            for(int j = 0; j < 7; ++ j){
                if(j <= 2 || j == 5)
                    continue;
                cur[0] = (cur[0] + pre[j])%MOD;
            }
            
            //End with L
            for(int j = 0; j < 7; ++ j){
                if(j == 0 || j == 5)
                    cur[1] = (cur[1] + pre[j])%MOD;
                else if(j == 1)
                    cur[2] = (cur[2] + pre[j])%MOD;
                else if(j == 6)
                    cur[3] = (cur[3] + pre[j])%MOD;
                else if(j == 3)
                    cur[4] = (cur[4] + pre[j])%MOD;
            }
            
            //End with P
            for(int j = 0; j < 7; ++ j){
                if(j <= 2 || j == 5)
                    cur[5] = (cur[5] + pre[j])%MOD;
                else
                    cur[6] = (cur[6] + pre[j])%MOD;
            }
            
            pre = cur;
        }
        for(int i = 0; i < 7; ++ i){
            ans = (ans + cur[i])%MOD;
        }
        return ans;
    }
};
