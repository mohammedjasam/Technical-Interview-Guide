/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 1<<30;

struct edge{
    int u,v;
    int next;
};
vector<int> head;
vector<edge> trees;
vector<int> val;
vector<bool> vis;
int num;
int n;
int ans;

void add(int u, int v){
    edge e;
    e.u = u;
    e.v = v;
    trees.push_back(e);
    trees[num].next = head[u];
    head[u] = num;
    num ++;
}

int dfs(int u, int tot){
    if(head[u] == -1){
        return val[u];
    }
    int sum = 0, tval;
    for(int i = head[u]; i != -1; i = trees[i].next){
        int v = trees[i].v;
        if(vis[v]) 
            continue;
        vis[v] = true;
        int tmp = dfs(v, tot);
        tval = tot - 2*tmp;
        if(tval < 0)
            tval = -tval;
        ans = min(ans, tval);
        sum += tmp;
    }
    sum += val[u];
    tval = tot - 2*sum;
    if(tval < 0)
        tval = -tval;
    ans = min(ans, tval);
    return sum;
}

int main(){
    int tot = 0;
    ans = inf;
    scanf("%d",&n);
    head.resize(n + 2);
    val.resize(n + 2);
    vis.resize(n + 2);
    for(int i = 0; i < n + 2; i ++)
        head[i] = -1;
    num = 0;
    for(int i = 1; i <= n; i ++){
        scanf("%d",&val[i]);
        tot += val[i];
    }
    int u,v;
    for(int i = 0; i < n - 1; i ++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    vis[1] = 1;
    dfs(1,tot);
    printf("%d\n",ans);
    return 0;
}
