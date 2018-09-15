/*
*
* Tag: Brute Force
* Time: O(nm)
* Space: O(1)
*/
class Solution {
private:
    const int expectedState = ((1<<9)-1);
private:
    vector<int> rowSum, columnSum;
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() < 3 || (grid.size() > 0 && grid[0].size() < 3)){
            return ans;
        }
        
        rowSum.resize(3);
        columnSum.resize(3);
        for(int i = 0; i <= grid.size() - 3; ++ i){
            int curState = 0;
            fill(rowSum.begin(), rowSum.end(), 0);
            fill(columnSum.begin(), columnSum.end(), 0);
            
            for(int j = 0; j <= grid[i].size() - 3; ++ j){
                int nextState = getSquareState(curState, i, j, grid);
                if(isValidState(nextState, i, j, grid)){
                    ++ ans;
                }
                
                curState = nextState;
            }
        }
        
        return ans;
    }
    
private:
    int getSquareState(int curState, int r, int c, vector<vector<int>>& grid){
        int nextState = curState;
        if(c > 0){
            for(int i = r; i < r + 3; ++ i){
                nextState ^= (1<<(grid[i][c - 1] - 1));
                rowSum[i - r] -= grid[i][c - 1];
            }
            columnSum[0] = columnSum[1];
            columnSum[1] = columnSum[2];
            columnSum[2] = 0;
            
        } else if(c == 0) {
            for(int i = r; i < r + 3; ++ i){
                for(int j = c; j < c + 2; ++ j){
                    nextState ^= (1<<(grid[i][j] - 1));
                    rowSum[i - r] += grid[i][j];
                    columnSum[j - c] += grid[i][j];
                }
            }
        }
        
        for(int i = r; i < r + 3; ++ i){
            nextState ^= (1<<(grid[i][c + 2] - 1));
            rowSum[i - r] += grid[i][c + 2];
            columnSum[2] += grid[i][c + 2];
        }
        
        return nextState;
    }
    
    bool isValidState(int state, int r, int c, vector<vector<int>>& grid){
        if(state != expectedState){
            return false;
        }
        
        int diagSum = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int antiDiagSum = grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c];
        
        return diagSum == antiDiagSum && rowSum[0] == rowSum[1] && rowSum[1] == rowSum[2] && columnSum[0] == columnSum[1] && columnSum[1] == columnSum[2] && diagSum == rowSum[0] && diagSum == columnSum[0];
    }
};
