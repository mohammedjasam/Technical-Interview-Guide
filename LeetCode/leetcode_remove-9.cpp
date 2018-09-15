/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int newInteger(int n) {
        int ans = 0, fac = 1;
        while(n > 0){
            ans += (n%9)*fac;
            n /= 9;
            fac *= 10;
        }
        
        return ans;
    }
};
