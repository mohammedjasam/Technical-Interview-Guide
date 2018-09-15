/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    /*
     * @param : a 2d boolean array
     * @param : an integer
     * @return: the number of Islands
     */
    int numsofIsland(vector<vector<bool>> grid, int k) {
        int num = 0;
        if(grid.size() == 0)
            return num;
        
        int numOfRows = grid.size(), numOfColumns = grid[0].size();
        for(int i = 0; i < numOfRows; ++ i){
            for(int j = 0; j < numOfColumns; ++ j){
                if(grid[i][j]){
                    int sizeOfIsland = 0;
                    pair<int,int> startPosition = make_pair(i, j);
                    dfs(startPosition, grid, sizeOfIsland);
                    if(sizeOfIsland >= k)
                        ++ num;
                }
            }
        }
        
        return num;
    }
    
private:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(pair<int,int> startPosition, vector<vector<bool>> &grid, int &sizeOfIsland) {
        int row = startPosition.first, column = startPosition.second;
        int numOfRows = grid.size(), numOfColumns = grid[0].size();
        
        grid[row][column] = false;
        ++ sizeOfIsland;
        
        for(int i = 0; i < 4; ++ i){
            int nextRow = row + dir[i][0], nextColumn = column + dir[i][1];
            if( isPositionInsideBoundary(nextRow, nextColumn, numOfRows, numOfColumns) && grid[nextRow][nextColumn] ) {
                pair<int,int> nextPosition = make_pair(nextRow, nextColumn);
                dfs(nextPosition, grid, sizeOfIsland);
            }
        }
    }
    
    bool isPositionInsideBoundary(int row, int column, int numOfRows, int numOfColumns){
        return row >= 0 && row < numOfRows && column >= 0 && column < numOfColumns;
    }
    
};
