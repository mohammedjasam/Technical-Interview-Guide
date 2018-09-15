/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
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
#include <unordered_set>
using namespace std;
const int N = 300010;
unordered_map<int,unordered_set<int>> g;
pair<int,long long> q[N], cur, nxt;
bool vis[N];
int n, m, u, v, component;
long long ans, cost, c[2], val;

void init(){
    g.clear();
    ans = LLONG_MAX;
    component = 0;
    memset(vis, 0, sizeof(vis));
}

void dfs(int u){
    vis[u] = 1;
    unordered_set<int>::iterator it = g[u].begin();
    for(; it != g[u].end(); ++ it ){
        if(!vis[*it]){
            dfs(*it);
        }
    }
}

int main(){
    int T;
    unordered_set<int>::iterator it;
    scanf("%d",&T);
    while(T --){
        init();
        scanf("%d%d%lld%lld",&n,&m,&c[0],&c[1]);
        for(int i = 0; i < m; ++ i){
            scanf("%d%d",&u,&v);
            g[u].insert(v);
            g[v].insert(u);
        }
        
        for(int i = 1; i <= n; ++ i){
            if(!vis[i]){
                ++ component;
                dfs(i);
            }
        }
        
        for(int i = component; i <= n; ++ i)
            ans = min(ans, i*c[0] + (n - i)*c[1]);
        printf("%lld\n",ans);
    }
    return 0;
}
