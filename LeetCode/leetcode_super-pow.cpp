/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    const int MOD = 1337;
private:
    int fastpow(int a, int b){
        if(a == 1 || !b)
            return 1;
        int res = 1, v = a%MOD;
        while(b){
            if(b&1){
                res *= v;
                res %= MOD;
            }
            b >>= 1;
            v = (v*v)%MOD;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        if(b.size() == 0)
            return ans;
        ans = fastpow(a, b[0]);
        for(int i = 1; i < b.size(); ++ i){
            ans = fastpow(ans, 10)*fastpow(a, b[i]);
            ans %= MOD;
        }
        return ans;
    }
};
