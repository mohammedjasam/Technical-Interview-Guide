/*
*
* Tag: Game (SG function)
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int N = 20;
const int M = 500;
int dir[4][2] = {-2,1,-2,-1,1,-2,-1,-2};
int sg[N][N];
int x, y, k;

int SGFun(int x, int y){
    if(sg[x][y] != -1)
        return sg[x][y];
    bool vis[M] = {};
    for(int i = 0; i < 4; ++ i){
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx >= 0 && nx < 15 && ny >= 0 && ny < 15){
            vis[SGFun(nx, ny)] = 1;
        }
    }
    int res = 0;
    while(vis[res]) ++ res;
    return sg[x][y] = res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    fill((int*)sg, (int*)sg + N*N, -1);
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&k);
        int ans = 0;
        for(int i = 0; i < k; ++ i){
            scanf("%d%d",&x,&y);
            -- x;
            -- y;
            ans^=SGFun(x, y);
        }
        puts(ans?"First":"Second");
    }
    return 0;
}
