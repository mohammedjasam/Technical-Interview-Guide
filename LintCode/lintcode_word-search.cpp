/*
*
* Tag: DFS
* Time: O(rc*(4^m))
* Space: O(rc)
*/
class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        if(word=="")
            return true;
        if(board.size() == 0)
            return false;
        int r = board.size(), c = board[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        bool isfind = false;
        for(int i = 0; i < r; ++ i){
            for(int j = 0; j < c; ++ j){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    dfs(board, vis, word, 1, i, j,r,c,isfind);
                    if(isfind)
                        break;
                    vis[i][j] = 0;
                }
            }
            if(isfind)
                break;
        }
        return isfind;
    }
    
    void dfs(vector<vector<char> > &board, vector<vector<bool>> &vis, string word, int len, int ir, int ic, int r, int c,bool &isfind){
        if(len >= word.size()){
            isfind = true;
            return ;
        }
        if(ir + 1 < r && !vis[ir + 1][ic] && board[ir + 1][ic] == word[len]){
            vis[ir + 1][ic] = 1;
            dfs(board, vis, word, len + 1, ir + 1, ic,r,c,isfind);
            if(isfind)
                return ;
            vis[ir + 1][ic] = 0;
        }
        if(ir - 1 >= 0 && !vis[ir - 1][ic] && board[ir - 1][ic] == word[len]){
            vis[ir - 1][ic] = 1;
            dfs(board, vis, word, len + 1, ir - 1, ic,r,c,isfind);
            if(isfind)
                return ;
            vis[ir - 1][ic] = 0;
        }
        if(ic + 1 < c && !vis[ir][ic + 1] && board[ir][ic + 1] == word[len]){
            vis[ir][ic + 1] = 1;
            dfs(board, vis, word, len + 1, ir, ic + 1,r,c,isfind);
            if(isfind)
                return ;
            vis[ir][ic + 1] = 0;
        }
        if(ic - 1 >= 0 && !vis[ir][ic - 1] && board[ir][ic - 1] == word[len]){
            vis[ir][ic - 1] = 1;
            dfs(board, vis, word, len + 1, ir, ic - 1,r,c,isfind);
            if(isfind)
                return ;
            vis[ir][ic - 1] = 0;
        }
    }
};
