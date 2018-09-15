/*
*
* Tag: Graph Theory (MST)
* Time: O(nlgn)
* Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 200010;
pair<int, pair<int, int>> edges[N], treeedges[N];
int root[N >> 1], head[N >> 1], etot, soncnt[N >> 1];
long long c[N << 1];
int n, m, u, v, w;

void init(){
    for(int i = 1; i <= n; ++ i){
        head[i] = -1;
        root[i] = i;
        soncnt[i] = 1;
    }
    etot = 0;
    memset(c, 0, sizeof(c));
}

inline void addedge(int u, int v, int w) {
    treeedges[etot] = make_pair(head[u], make_pair(v, w));
    head[u] = etot++;
}

inline void addedge(const pair<int, pair<int, int>>& edge) {
    int u = edge.second.first;
    int v = edge.second.second;
    int w = edge.first;
    addedge(u, v, w);
    addedge(v, u, w);
}

inline int findset(int x){
    return root[x] = root[x] == x?x:findset(root[x]);
}

inline void unionset(const pair<int, pair<int, int>>& edge) {
    int u = findset(edge.second.first);
    int v = findset(edge.second.second);
    if (u != v) {
        root[u] = v;
        addedge(edge);
    }
}

inline void dfs(int n, int u, int f){
    for(int e = head[u]; ~e; e = treeedges[e].first){
        int v = treeedges[e].second.first;
        if (v != f) {
            dfs(n, v, u);
            soncnt[u] += soncnt[v];
            c[treeedges[e].second.second] += 1LL * (n - soncnt[v]) * soncnt[v];
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    init();
    for(int i = 0; i < m; ++ i){
        scanf("%d%d%d",&u,&v,&w);
        edges[i] = make_pair(w, make_pair(u, v));
    }
    sort(edges, edges + m);
    for(int i = 0; i < m; ++ i)
        unionset(edges[i]);
    dfs(n, 1, -1);
    int mx = N<<1;
    mx -= 2;
    for(int i = 0; i < mx; ++ i){
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
    int lastOnePos = 0;
    for (lastOnePos = mx; lastOnePos > 0 && !c[lastOnePos]; -- lastOnePos);
        for (int i = lastOnePos; i >= 0; -- i)
            printf("%d", c[i]);
    puts("");
    return 0;
}
