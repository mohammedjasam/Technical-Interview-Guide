/*
*
* Tag: DFS
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
const int dir[8][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int mp[N][N], ans, n, m;

void dfs(int r, int c, int &cnt){
    mp[r][c] = 0;
    ans = max(ans, cnt);
    int nr = 0, nc = 0;
    for(int i = 0; i < 8; ++ i){
        nr = r + dir[i][0], nc = c + dir[i][1];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && mp[nr][nc] == 1){
            ++ cnt;
            dfs(nr, nc, cnt);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            scanf("%d",&mp[i][j]);
        }
    }
    ans = 0;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            if(mp[i][j] == 1){
                int cnt = 1;
                dfs(i, j, cnt);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
