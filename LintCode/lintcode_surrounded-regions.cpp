/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        if(!board.size())
            return ;
        vis.resize(board.size());
        for(int i = 0; i < board.size(); ++ i){
            vector<int> tmp(board[0].size());
            vis[i] = tmp;
        }
        
        for(int i = 0; i < vis.size(); ++ i){
            for(int j = 0; j < vis[0].size(); ++ j){
                if(!vis[i][j]){
                    if(board[i][j] == 'X'){
                        vis[i][j] = 2;
                    }else{
                        if(!i || i == vis.size() - 1 || !j || j == vis[0].size() - 1){
                            vis[i][j] = 1;
                            dfs(i, j, board);
                        }else{
                            vis[i][j] = 2;
                        }
                    }
                }
            }
        }
        
         for(int i = 0; i < vis.size(); ++ i){
            for(int j = 0; j < vis[0].size(); ++ j){
                if(vis[i][j] != 1)
                    board[i][j] = 'X';
            }
         }
            
    }
    
    void dfs(int x, int y, vector<vector<char>>& board){
        for(int i = 0; i < 4; ++ i){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && vis[nx][ny] != 1 && board[nx][ny] == 'O'){
                vis[nx][ny] = 1;
                dfs(nx, ny, board);
            }
        }
    }
private:
vector<vector<int>> vis;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
