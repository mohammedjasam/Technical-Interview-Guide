/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 20;
const int N = 20;
vector<vector<bool> > vis(M, vector<bool>(N));
vector<vector<int> > board(M, vector<int>(N));
int ans;
int n, m;

void dfs(int r, int c, int &cnt){
    if(r + 1 < m && board[r + 1][c] && !vis[r + 1][c]){
        vis[r + 1][c] = 1;
        ++ cnt;
        dfs(r + 1, c, cnt);
    }
    if(c + 1 < n && board[r][c + 1] && !vis[r][c + 1]){
        vis[r][c + 1] = 1;
        ++ cnt;
        dfs(r, c + 1, cnt);
    }
    if(r + 1 < m && c + 1 < n && board[r + 1][c + 1] && !vis[r + 1][c + 1]){
        vis[r + 1][c + 1] = 1;
        ++ cnt;
        dfs(r + 1, c + 1, cnt);
    }
    if(r + 1 < m && c - 1 >= 0 && board[r + 1][c - 1] && !vis[r + 1][c - 1]){
        vis[r + 1][c - 1] = 1;
        ++ cnt;
        dfs(r + 1, c - 1, cnt);
    }
    if(c - 1 >= 0 && board[r][c - 1] && !vis[r][c - 1]){
        vis[r][c - 1] = 1;
        ++ cnt;
        dfs(r, c - 1, cnt);
    }
    if(r - 1 >= 0 && board[r - 1][c] && !vis[r - 1][c]){
        vis[r - 1][c] = 1;
        ++ cnt;
        dfs(r - 1, c, cnt);
    }
    if(r - 1 >= 0 && c - 1 >= 0 && board[r - 1][c - 1] && !vis[r - 1][c - 1]){
        vis[r - 1][c - 1] = 1;
        ++ cnt;
        dfs(r - 1, c - 1, cnt);
    }
    if(r - 1 >= 0 && c + 1 < n && board[r - 1][c + 1] && !vis[r - 1][c + 1]){
        vis[r - 1][c + 1] = 1;
        ++ cnt;
        dfs(r - 1, c + 1, cnt);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&m,&n);
    ans = INT_MIN;
    for(int i = 0; i < m; ++ i){
        for(int j = 0; j < n; ++ j)
            scanf("%d", &board[i][j]);
    }
    
    for(int i = 0; i < m; ++ i){
        for(int j = 0; j < n; ++ j){
            if(board[i][j] && !vis[i][j]){
                vis[i][j] = 1;
                int cnt = 1;
                dfs(i, j, cnt);
                ans = max(ans, cnt);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
