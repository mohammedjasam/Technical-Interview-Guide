/*
* 
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> tree;
vector<bool> vis;
int n;
int max_val, min_val;

void dfs(int u, int &cnt){
    for(int i = 0; i < tree[u].size(); ++ i){
        int v = tree[u][i];
        if(!vis[v]){
            ++ cnt;
            vis[v] = 1;
            dfs(v, cnt);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    tree.resize(2*n);
    vis.resize(2*n);
    for(int i = 0; i < 2*n; ++ i)
        vis[i] = -1;
    for(int i = 0; i < n; ++ i){
        int u, v;
        scanf("%d%d",&u,&v);
        -- u;
        -- v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        vis[u] = vis[v] = 0;
    }
    max_val = 0;
    min_val = 3*n;
    int cnt = 0;
    for(int i = 0; i < 2*n; ++ i){
        cnt = 0;
        if(!vis[i]){
            vis[i] = 1;
            ++ cnt;
            dfs(i, cnt);
            max_val = max(max_val, cnt);
            min_val = min(min_val, cnt);
        }
    }
    printf("%d %d\n",min_val, max_val);
    return 0;
}
