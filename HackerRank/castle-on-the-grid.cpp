/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
const int N = 110;
struct pos{
    int x, y, dir;
}poss0, poss1, poss2, poss3;
int n;
char mp[N][N];
int ans[N][N][4];
bool inq[N][N];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
pair<int,int> s, t;

void init(){
    for(int i = 0; i < N; ++ i){
        for(int j = 0; j < N; ++ j){
            ans[i][j][0] = ans[i][j][1] = ans[i][j][2] = ans[i][j][3] =INT_MAX;
        }
    }
}

void bfs(){
    queue<pos> q;
    poss0.x = s.first, poss0.y = s.second, poss0.dir = 0;
    q.push(poss0);
    poss1.x = s.first, poss1.y = s.second, poss1.dir = 1;
    q.push(poss1);
    poss2.x = s.first, poss2.y = s.second, poss2.dir = 2;
    q.push(poss2);
    poss3.x = s.first, poss3.y = s.second, poss3.dir = 3;
    q.push(poss3);
    ans[s.first][s.second][0] = ans[s.first][s.second][1] = ans[s.first][s.second][2] = ans[s.first][s.second][3] = 0;
    while(!q.empty()){
        pos cur = q.front();
        q.pop();
        if(cur.x == t.first && cur.y == t.second)
            continue;
        for(int i = 0; i < 4; ++ i){
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && mp[nx][ny] != 'X'){
                int val = ans[cur.x][cur.y][cur.dir];
                if(cur.dir != i)
                    ++ val;
                if(ans[nx][ny][i] > val){
                    ans[nx][ny][i] = val;
                    pos nxt;
                    nxt.x = nx, nxt.y = ny, nxt.dir = i;
                    q.push(nxt);
                }
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i){
        scanf("%s",mp[i]);
    }
    scanf("%d%d%d%d",&s.first,&s.second,&t.first,&t.second);
    bfs();
    int res = ans[t.first][t.second][0];
    for(int i = 1; i < 4; ++ i){
        res = min(res, ans[t.first][t.second][i]);
    }
    printf("%d\n",res + 1);
    return 0;
}
