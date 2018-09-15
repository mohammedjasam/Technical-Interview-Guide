/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if(n <= 1 || !k)
            return n*k;
        int a = k, b = k*(k - 1), c = 0;
        for(int i = 2; i < n; ++ i){
            c = (k - 1)*(a + b);
            a = b;
            b = c;
        }
        
        return a+b;
    }
};
