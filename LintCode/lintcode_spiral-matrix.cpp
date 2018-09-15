/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> ans;
        if(!matrix.size())
            return ans;
            
        int cnt = 0, tot = matrix.size()*matrix[0].size(), n = matrix.size(), m = matrix[0].size();
        int r = 0, c = 0, dir = 0;
        vector<vector<bool>> vis(n, vector<bool>(m));
        ans.resize(tot);
        while(cnt < tot){
            if(!dir){
                vis[r][c] = 1;
                ans[cnt ++] = matrix[r][c];
                ++ c;
                if(c >= m || vis[r][c]){
                    dir = 1;
                    -- c;
                    ++ r;
                }
            }else if(dir == 1){
                vis[r][c] = 1;
                ans[cnt ++] = matrix[r][c];
                ++ r;
                if(r >= n || vis[r][c]){
                    dir = 2;
                    -- r;
                    -- c;
                }
            }else if(dir == 2){
                vis[r][c] = 1;
                ans[cnt ++] = matrix[r][c];
                -- c;
                if(c < 0 || vis[r][c]){
                    dir = 3;
                    -- r;
                    ++ c;
                }
            }else{
                vis[r][c] = 1;
                ans[cnt ++] = matrix[r][c];
                -- r;
                if(r < 0 || vis[r][c]){
                    dir = 0;
                    ++ r;
                    ++ c;
                }
            }
        }
        
        return ans;
    }
};
