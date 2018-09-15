/*
*
* Tag: DFS + Union Find
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
private:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    unordered_map<int,int> parentOfCell;
    unordered_map<int,int> setSize;
public:
    int largestIsland(vector<vector<int>>& grid) {
        init(grid);
        
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(grid[i][j] == 1 && parentOfCell[i*m + j] == -1){
                    int setNum = i*m + j;
                    dfs(setNum, i, j, grid);
                    ans = max(ans, setSize[setNum]);
                }
            }
        }
        
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(grid[i][j] == 1){
                    continue;
                }
                
                for(int p = 0; p < 4; ++ p){
                    int firstSetR = i + dir[p][0], firstSetC = j + dir[p][1];
                    if(firstSetR >= 0 && firstSetR < n && firstSetC >= 0 && firstSetC < m && grid[firstSetR][firstSetC] == 1){
                        int firstSetNum = parentOfCell[firstSetR*m + firstSetC];
                        int res = setSize[firstSetNum] + 1;
                        unordered_set<int> visitedSet;
                        
                        visitedSet.insert(firstSetNum);
                        for(int q = 0; q < 4; ++ q){
                            int secondSetR = i + dir[q][0], secondSetC = j + dir[q][1];
                            if(secondSetR >= 0 && secondSetR < n && secondSetC >= 0 && secondSetC < m && grid[secondSetR][secondSetC] == 1){
                                int secondSetNum = parentOfCell[secondSetR*m + secondSetC];
                                if(visitedSet.count(secondSetNum) == 0 ){
                                    res += setSize[secondSetNum];
                                    visitedSet.insert(secondSetNum);
                                }
                            }
                        }
                        
                        ans = max(ans, res);
                        
                    }
                }
            }
        }
        
        return ans == 0 ? 1 : ans;
    }
    
private:
    void init(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                parentOfCell[i*m + j] = -1;
            }
        }
        
        return ;
    }
    
    void dfs(int setNum, int r, int c, vector<vector<int>>& grid){
        parentOfCell[r*grid[0].size() + c] = setNum;
        ++ setSize[setNum];
        
        for(int i = 0; i < 4; ++ i){
            int nextR = r + dir[i][0], nextC = c + dir[i][1];
            if(nextR >= 0 && nextR < grid.size() && nextC >= 0 && nextC < grid[0].size() && grid[nextR][nextC] == 1 && parentOfCell[nextR*grid[0].size() + nextC] == -1){
                dfs(setNum, nextR, nextC, grid);
            }
        }
        
        return ;
    }
};
