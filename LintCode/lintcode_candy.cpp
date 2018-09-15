/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        // Write your code here
        vector<int> candy;
        if(!ratings.size())
            return 0;
        int n = ratings.size();
        candy.resize(n);
        for(int i = 1; i < n; ++ i){
            if(ratings[i] > ratings[i - 1])
                candy[i] = max(candy[i], candy[i - 1] + 1);
        }
        for(int i = n - 2; i >= 0; -- i){
            if(ratings[i] > ratings[i + 1])
                candy[i] = max(candy[i], candy[i + 1] + 1);
        }
        return accumulate(&candy[0], &candy[0] + n, n) ;
    }
};
