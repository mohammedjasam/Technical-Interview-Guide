/*
*
* Tag: DFS
* Time: O(m*n^2)
* Space: O(n^2)
*/
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty()) {
            return true;
        }
        if (board.empty()) {
            return false;
        }
        
        int m = board.size();
        int n = board[0].size();
        if (word.size() > m * n) {
            return false;
        }
        
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, string &word, int r, int c, int k) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c]) {
            return false;
        }
        
        if (k == word.size() - 1) {
            return (board[r][c] == word[k]);
        }
        if (board[r][c] != word[k]) {
            return false;
        }
        
        visited[r][c] = true;
        bool res = dfs(board, visited, word, r - 1, c, k + 1) || dfs(board, visited, word, r + 1, c, k + 1) || dfs(board, visited, word, r, c - 1, k + 1) || dfs(board, visited, word, r, c + 1, k + 1);
        visited[r][c] = false;
        
        return res;
    }
};
