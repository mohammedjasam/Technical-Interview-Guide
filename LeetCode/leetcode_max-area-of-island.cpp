/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(1)
*/
class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0){
            return ans;
        }
        
        int numOfRows = grid.size(), numOfColumns = grid[0].size();
        for(int i = 0; i < numOfRows; ++ i){
            for(int j = 0; j < numOfColumns; ++ j){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    dfs(i, j, grid, cnt);
                    ans = max(ans, cnt);
                }
            }
        }
        
        return ans;
    }

private:
    void dfs(int row, int column, vector<vector<int>>& grid, int &cnt){
        grid[row][column] = 0;
        ++ cnt;
        
        int numOfRows = grid.size(), numOfColumns = grid[0].size();
        for(int i = 0; i < 4; ++ i){
            int nextRow = row + dir[i][0], nextColumn = column + dir[i][1];
            if(nextRow >= 0 && nextRow < numOfRows && nextColumn >= 0 && nextColumn < numOfColumns && grid[nextRow][nextColumn] == 1){
                dfs(nextRow, nextColumn, grid, cnt);
            }
        }
    }
};
