/*
* Algorithm: DP
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        const int n = ratings.size();
        vector<int> res = vector<int>(n,0);
        for(int i = 1; i < n; i ++){
            if(ratings[i] > ratings[i - 1]){
                res[i] = max(res[i], res[i - 1] + 1);
            }
        }
        for(int i = n - 2; i >= 0; i --){
            if(ratings[i] > ratings[i + 1]){
                res[i] = max(res[i], res[i + 1] + 1);
            }
        }
        return accumulate(&res[0],&res[0] + n, n);
    }
};

