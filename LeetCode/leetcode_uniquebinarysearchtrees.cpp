/*
* Algorithm: O(n)
* Time complexity: O(n^2)
* Memory complexity: O(n^2)
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n + 1, 0);
        
        ans[0] = 1;
        ans[1] = 1;
        for(int i = 2; i <= n; i ++){
            for(int k = 1; k <= i; k ++){
                ans[i] += ans[k - 1]*ans[i - k];
            }
        }
        return ans[n];
    }
};
