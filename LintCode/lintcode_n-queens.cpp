/*
*
* Tag: DFS
* Time: O(n^n)
* Space: O(n)
*/
class Solution {
public:
    int row[1010],col[1010];
    vector<vector<string> > ans;
    vector<vector<string> > solveNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ans.clear();
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        dfs(0,n);
        return ans;
    }
    
    void dfs(int r,int n){
        if(r == n){
            vector<string> tmps;
            for(int i = 0; i < n; i ++){
                string tmp(n,'.');
                tmp[row[i]] = 'Q';
                tmps.push_back(tmp);
            }
            ans.push_back(tmps);
            return ;
        }
        int i,j;
        for(i = 0; i < n; i ++){
            if(col[i] == 0){
                for(j = 0; j < r; j ++)
                    if(abs(r - j) == abs(i - row[j])) break;
                if(j == r){
                    row[r] = i;
                    col[i] = 1;
                    dfs(r+1,n);
                    row[r] = 0;
                    col[i] = 0;
                }
            }
        }
    }
};

