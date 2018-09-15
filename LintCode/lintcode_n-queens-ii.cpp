/*
*
* Tag: DFS
* Time: O(n!)
* Space: O(n)
*/
class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        if(n == 0)
            return 0;
        vector<bool> column(n);
        vector<bool> diaup(2*n), diadwn(2*n);
        int tot = 0;
        for(int i = 0; i < n; i ++){
            int d1 = i, d2 = -i + n;
            column[i] = 1;
            diaup[d1] = 1;
            diadwn[d2] = 1;
            dfs(1,column,diaup,diadwn,tot,n);
            column[i] = 0;
            diaup[d1] = 0;
            diadwn[d2] = 0;
        }
        return tot;
    }
    
    void dfs(int dep, vector<bool> column, vector<bool> diaup, vector<bool> diadwn, int &tot, int n){
        if(dep >= n){
            tot ++;
            return ;
        }
        for(int i = 0; i < n; i ++){
            int d1 = dep + i, d2 = dep - i + n;
            if(!column[i] && !diaup[d1] && !diadwn[d2]){
                column[i] = 1;
                diaup[d1] = 1;
                diadwn[d2] = 1;
                dfs(dep + 1,column,diaup,diadwn,tot,n);
                column[i] = 0;
                diaup[d1] = 0;
                diadwn[d2] = 0;
            }
        }
    }
};

