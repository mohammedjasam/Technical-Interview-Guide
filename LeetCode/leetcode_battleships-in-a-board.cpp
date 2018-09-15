/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        if(board.size() == 0)
            return ans;
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int lb = 0, rb = 0, ub = 0, db = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(board[i][j] == 'X' && !vis[i][j]){
                    lb = rb = j, ub = db = i;
                    dfs(i, j, lb, rb, ub, db, board, vis, n, m);
                    ans += checkBattle(lb, rb, ub, db);
                }
            }
        }
        return ans;
    }
private:
    void dfs(int r, int c, int &lb, int &rb, int &ub, int &db, vector<vector<char>>& board, vector<vector<bool>> &vis, int n, int m){
        vis[r][c] = 1;
        int nr = 0, nc = 0;
        for(int i = 0; i < 4; ++ i){
            nr = r + dir[i][0], nc = c + dir[i][1];
            if((nr >= 0 && nr < n && nc >= 0 && nc < m) && board[nr][nc] == 'X' && !vis[nr][nc]){
                lb = min(lb, nc), rb = max(rb, nc), ub = min(ub, nr), db = max(db, nr);
                dfs(nr, nc, lb, rb, ub, db, board, vis, n, m);
            }
        }
    }
    
    int checkBattle(int lb, int rb, int ub, int db){
        int res = 0, len = rb - lb + 1, wid = db - ub + 1;
        printf("len = %d, wid = %d\n",len,wid);
        if(len == 1 && wid == 1)
            ++ res;
        else if(len == 1)
            ++ res;
        else if(wid == 1)
            ++ res;
        return res;
    }
    
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
