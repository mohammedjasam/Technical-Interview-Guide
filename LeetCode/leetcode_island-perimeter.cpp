/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0)
            return ans;
        int n = grid.size(), m = grid[0].size(), x = 0, y = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; ++ k){
                        x = i + dir[k][0], y = j + dir[k][1];
                        if(!isInMap(x, y, n, m) || grid[x][y] == 0)
                            ++ ans;
                    }
                }
            }
        }
        return ans;
    }
    
private:
    bool isInMap(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
private:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
};
