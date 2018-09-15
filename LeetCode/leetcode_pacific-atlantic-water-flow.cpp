/*
*
* Tag: DFS
* Time: O(n^3)
* Space: O(n^2)
*/
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ans;
        if(matrix.size() == 0)
            return ans;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> reach_pac(n, vector<bool>(m, false)), reach_alt(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; ++ i){
            reach_pac[i][0] = 1;
            dfs(i, 0, n, m, matrix[i][0], reach_pac, matrix);
            reach_alt[i][m - 1] = 1;
            dfs(i, m - 1, n, m, matrix[i][m - 1], reach_alt, matrix);
        }
        
        for(int i = 0; i < m; ++ i){
            reach_pac[0][i] = 1;
            dfs(0, i, n, m, matrix[0][i], reach_pac, matrix);
            reach_alt[n - 1][i] = 1;
            dfs(n - 1, i, n, m, matrix[n - 1][i], reach_alt, matrix);
        }
        
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(reach_pac[i][j] && reach_alt[i][j])
                    ans.push_back(make_pair(i, j));
            }
        }
        return ans;
    }

private:
    void dfs(int x, int y, int n, int m, int h, vector<vector<bool>> &vis, vector<vector<int>>& matrix){
        int nx = 0, ny = 0;
        for(int i = 0; i < 4; ++ i){
            nx = x + dir[i][0], ny = y + dir[i][1];
            if(check(nx, ny, n, m) && !vis[nx][ny] && h <= matrix[nx][ny]){
                vis[nx][ny] = 1;
                dfs(nx, ny, n, m, matrix[nx][ny], vis, matrix);
            }
        }
    }
    
    bool check(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
private:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
};
