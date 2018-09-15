/*
*
* Tag: Game Theory
* Time: O(2^n)
* Space: O(2^n)
*/
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal)
            return true;
        if((1 + maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal)
            return false;
        int state = (1<<maxChoosableInteger)-1;
        return dfs(state, maxChoosableInteger, desiredTotal);
    }
    
    bool dfs(unsigned int state, unsigned int size, int tot){
        if(dp.count(state) > 0)
            return dp[state];
        if(tot - 1 < size && (state > (1<<tot-1))){
            dp[state] = true;
            return true;
        }
        for(int i = 0, bit = 1; i < size; ++i, bit <<= 1){
            if((state & bit) == 0)
                continue;
            state^=bit;
            if(!dfs(state, size, tot - i - 1)){
                state |= bit;
                dp[state] = true;
                return true;
            }
            state |= bit;
        }
        dp[state] = false;
        return false;
    }
    
private:
    unordered_map<unsigned int, bool> dp;
};
