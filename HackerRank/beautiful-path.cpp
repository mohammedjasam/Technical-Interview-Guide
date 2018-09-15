/*
*
* Tag: DFS
* Time: O(C(n+m)) where C=2048
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
const int NN = 3100;
const int M = 11010;
struct edge{
    int u, v, w;
    int nxt;
}e[2*M];
int head[N], num;
bool vis[N][NN];
int n, m, s, t;

void init(){
    num = 0;
    for(int i = 0; i < N; ++ i){
        head[i] = -1;
    }
    memset(vis, 0, sizeof(vis));
}

void addedge(int u, int v, int w){
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].nxt = head[u];
    head[u] = num ++;
}

void dfs(int u, int val){
    if(u == t){
        vis[t][val] = 1;
        return ;
    }
    vis[u][val] = 1;
    for(int i = head[u]; i != -1; i = e[i].nxt){
        int v = e[i].v, w = e[i].w;
        if(vis[v][val|w])
            continue;
        dfs(v, val|w);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++ i){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    scanf("%d%d",&s,&t);
    dfs(s, 0);
    bool isfind = false;
    int ans = 0;
    for(int i = 0; i < NN; ++ i){
        if(vis[t][i]){
            isfind = true;
            ans = i;
            break;
        }
    }
    if(isfind)
        printf("%d\n",ans);
    else
        puts("-1");
    return 0;
}
