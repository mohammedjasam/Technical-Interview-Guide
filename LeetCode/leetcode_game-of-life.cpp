/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
// live -> stillLive and diedToLive
// died -> stillDied and liveToDied
class Solution {
private:
    int dir[8][2] = {{-1, 0},{-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0){
            return ;
        }
        
        int n = board.size(), m = board[0].size();
        for(int r = 0; r < n; ++ r){
            for(int c = 0; c < m; ++ c){
                
                int numOfLiveCells = 0;
                for(int k = 0; k < 8; ++ k){
                    int nextR = r + dir[k][0], nextC = c + dir[k][1];
                    if(check(nextR, nextC, n, m) && (board[nextR][nextC]&1) == 1){
                        ++ numOfLiveCells;
                    }
                }
                
                if(board[r][c] == 1){
                    if(numOfLiveCells < 2 || numOfLiveCells > 3) {
                        board[r][c] = 3;
                    }
                } else {
                    if(numOfLiveCells == 3){
                        board[r][c] = 2;
                    }
                }
                
            }
        }
        
        for(int r = 0; r < n; ++ r){
            for(int c = 0; c < m; ++ c){
                if(board[r][c] == 0 || board[r][c] == 3) {
                    board[r][c] = 0;
                } else {
                    board[r][c] = 1;
                }
            }
        }
        
        return ;
    }
private:
    bool check(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};
