/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
    	long long ans = 0;
    	long long div = 5, mul = 5;
    	while(n/div){
    	    ans += n/div;
    	    div *= mul;
        }
        return ans;
    }
};

