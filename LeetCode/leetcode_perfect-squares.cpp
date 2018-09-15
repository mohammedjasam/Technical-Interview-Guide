/*
*
* Tag: DP
* Time: O(n^1.5)
* Space: O(n)
*/
class Solution {
public:
    int numSquares(int n) {
        if(n <= 1){
            return 1;
        }
        
        vector<int> rcd(n), dp(n + 1);
        int cnt = 0, bnd = sqrt(n*1.0);
        for(int i = 1; i <= bnd; ++ i){
            rcd[cnt ++] = i*i;
        }
        for(int i = 1; i <= n; ++ i){
            dp[i] = n + 1;
        }
        for(int i = 0; i < cnt; ++ i){
            dp[rcd[i]] = 1;
        }
        for(int i = 1; i < n; ++ i){
            if(dp[i] == -1)
                continue;
            for(int j = 0; j < cnt; ++ j){
                int nd = i + rcd[j];
                if(nd > n)
                    break;
                dp[nd] = min(dp[nd], dp[i] + 1);
            }
        }
        
        return dp[n];
    }
};

/*
*
* Tag: Math
* Time: O(n^0.5)
* Space: O(1)
*/
class Solution {
public:
    int numSquares(int n) {
        if(n <= 1){
            return 1;
        }
        
        while((n&3) == 0){
            n >>= 2;
        }
        
        if((n&7) == 7){
            return 4;
        }
        
        if(isSquare(n)) {
            return 1;
        }
        
        int squareVal = (int)sqrt(n);
        for(int i = 1; i <= squareVal; ++ i){
            if(isSquare(n - i*i)){
                return 2;
            }
        }
        
        return 3;
    }
    
private:
    bool isSquare(int n){
        int squareVal = (int)sqrt(n);
        return n == squareVal*squareVal;
    }
};
