/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 30;
const int M = 900;
const int dir[4][2] = {{-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
bool vis[N][N];
int ans[N][N], n, fnt, rear;
pair<pair<int,int>,int> q[M];

int bfs(int a, int b){
    pair<pair<int,int>,int> cur = make_pair(make_pair(0, 0), 0), nxt;
    fnt = rear = 0;
    q[rear ++] = cur;
    memset(vis, 0, sizeof(vis));
    while(fnt < rear){
        cur = q[fnt ++];
        for(int i = 0; i < 4; ++ i){
            nxt = make_pair(make_pair(cur.first.first + dir[i][0]*a, cur.first.second + dir[i][1]*b), cur.second + 1);
            if(nxt.first.first == n - 1 && nxt.first.second == n - 1)
                return nxt.second;
            if((nxt.first.first >= 0 && nxt.first.first < n) && (nxt.first.second >= 0 && nxt.first.second < n) && !vis[nxt.first.first][nxt.first.second]){
                vis[nxt.first.first][nxt.first.second] = 1;
                q[rear ++] = nxt;
            }
        }
        for(int i = 0; i < 4; ++ i){
            nxt = make_pair(make_pair(cur.first.first + dir[i][0]*b, cur.first.second + dir[i][1]*a), cur.second + 1);
            if(nxt.first.first == n - 1 && nxt.first.second == n - 1)
                return nxt.second;
            if(nxt.first.first == n - 1 && nxt.first.second == n - 1)
                return nxt.second;
            if((nxt.first.first >= 0 && nxt.first.first < n) && (nxt.first.second >= 0 && nxt.first.second < n) && !vis[nxt.first.first][nxt.first.second]){
                vis[nxt.first.first][nxt.first.second] = 1;
                q[rear ++] = nxt;
            }
        }
    }
    return -1;
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            ans[i][j] = bfs(i,j);
        }
    }
    for(int i = 1; i < n; ++ i){
        for(int j = 1; j < n; ++ j){
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
