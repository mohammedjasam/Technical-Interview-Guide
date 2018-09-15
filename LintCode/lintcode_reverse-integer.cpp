/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        int ans = 0;
        int posmax = INT_MAX, negmax = INT_MIN;
        if(!n)
            return ans;
        bool neg = n<0?true:false;
        while(n){
            if((!neg && (ans > posmax/10 || (ans == posmax/10 && n > posmax))) || 
            (neg && (ans < negmax/10 || (ans == negmax/10 && n < negmax)))){
                ans = 0;
                break;
            }
            ans *= 10;
            ans += (n);
            n /= 10;
        }
        return ans;
    }
};
