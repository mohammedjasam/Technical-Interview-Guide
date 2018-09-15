/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*
*/
class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        vector<int> cnt(10);
        for(int i = 0; i <= n; ++ i){
            if(i < 10)
                ++ cnt[i];
            else{
                int u = i;
                while(u){
                    int v = u;
                    ++ cnt[v];
                    u /= 10;
                }
            }
        }
        return cnt[k];
    }
};
