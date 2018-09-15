#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20;
bool board[N][N], vis[N][N];
int dir[4][2] = {{-2,1},{-2,-1},{1,-2},{-1,-2}};

void dfs(int x, int y){
    int res = 1;
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++ i){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx >= 1 && nx <= 15 && ny >= 1 && ny <= 15 ){
            if(!vis[nx][ny])
                dfs(nx, ny);
            res &= board[nx][ny];
        }
    }
    board[x][y] = (res^1);
}

void init(){
    memset(board, 0, sizeof(board));
    memset(vis, 0, sizeof(vis));
    vis[1][1] = vis[2][1] = vis[1][2] = vis[2][2] = 1;
    for(int i = 1; i <= 15; ++ i){
        for(int j = 1; j <= 15; ++ j){
            if(vis[i][j])
                continue;
            dfs(i, j);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    int T;
    scanf("%d",&T);
    while(T --){
        int x, y;
        scanf("%d%d",&x,&y);
        if(board[x][y])
            puts("First");
        else
            puts("Second");
    }
    return 0;
}
