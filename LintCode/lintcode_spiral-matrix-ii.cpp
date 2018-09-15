/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        if(!n)
            return ans;
            
        int cnt = 1, tot = n*n;
        int r = 0, c = 0, dir = 0;
        ans.resize(n);
        for(int i = 0; i < n; ++ i){
            vector<int> tmp(n);
            ans[i] = tmp;
        }
        vector<vector<bool>> vis(n, vector<bool>(n));
        while(cnt <= tot){
            if(!dir){
                vis[r][c] = 1;
                ans[r][c] = cnt ++;
                ++ c;
                if(c >= n || vis[r][c]){
                    dir = 1;
                    -- c;
                    ++ r;
                }
            }else if(dir == 1){
                vis[r][c] = 1;
                ans[r][c] = cnt ++;
                ++ r;
                if(r >= n || vis[r][c]){
                    dir = 2;
                    -- r;
                    -- c;
                }
            }else if(dir == 2){
                vis[r][c] = 1;
                ans[r][c] = cnt ++;
                -- c;
                if(c < 0 || vis[r][c]){
                    dir = 3;
                    -- r;
                    ++ c;
                }
            }else{
                vis[r][c] = 1;
                ans[r][c] = cnt ++;
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
