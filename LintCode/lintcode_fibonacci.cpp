/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if(n == 1)
            return 0;
        if(n == 2)
            return 1;
        int pre = 0, cur = 1;
        for(int i = 3; i <= n; ++ i){
            int tmp = cur;
            cur += pre;
            pre = tmp;
        }
        return cur;
    }
};

