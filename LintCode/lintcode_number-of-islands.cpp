/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int ans = 0;
        if(!grid.size())
            return ans;
        int r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; ++ i){
            for(int j = 0; j < c; ++ j){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    dfs(i, j, r, c, grid);
                    ++ ans;
                }
            }
        }
        
        return ans;
    }
    
    void dfs(int i_sta, int j_sta, int r, int c, vector<vector<bool>>& grid){
        if(i_sta + 1 < r && grid[i_sta + 1][j_sta]){
            grid[i_sta + 1][j_sta] = 0;
            dfs(i_sta + 1, j_sta, r, c, grid);
        }
        if(j_sta + 1 < c && grid[i_sta][j_sta + 1]){
            grid[i_sta][j_sta + 1] = 0;
            dfs(i_sta, j_sta + 1, r, c, grid);
        }
        if(i_sta - 1 >= 0 && grid[i_sta - 1][j_sta]){
            grid[i_sta - 1][j_sta] = 0;
            dfs(i_sta - 1, j_sta, r, c, grid);
        }
        if(j_sta - 1 >= 0 && grid[i_sta][j_sta - 1]){
            grid[i_sta][j_sta - 1] = 0;
            dfs(i_sta, j_sta - 1, r, c, grid);
        }
    }
};
