/*
*
* Tag: DP
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int ans = 0;
        if(!grid.size())
            return ans;
        int n = grid.size(), m = grid[0].size();
        for(int  i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(!i && !j)
                    continue;
                int sumup = INT_MAX, sumleft = INT_MAX;
                if(i)
                    sumup = grid[i][j] + grid[i - 1][j];
                if(j)
                    sumleft = grid[i][j] + grid[i][j - 1];
                grid[i][j] = min(sumup, sumleft);
            }
        }
        return grid[n - 1][m - 1];
    }
};

