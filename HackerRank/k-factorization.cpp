/*
*
* Tag: DFS
* Time: O(m*lgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 110;
const int M = 1000100;
unordered_map<long long, int> vis;
unordered_map<long long, long long> path;
long long n, arr[N], k;
long long stk[M], top;

void dfs(long long cur, long long prev, int dep){
    if(cur > 1){
        if(vis.find(cur) != vis.end() && vis[cur] <= dep)
            return ;
        vis[cur] = dep;
        path[cur] = prev;
    }
    
    if(cur >= n)
        return ;
    
    long long nxt = 0;
    for(int i = 0; i < k; ++ i){
        nxt = cur*arr[i];
        if(nxt > n)
            break;
        dfs(nxt, cur, dep + 1);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%lld%lld",&n,&k);
    for(int i = 0; i < k; ++ i)
        scanf("%lld",&arr[i]);
    sort(arr, arr + k);
    if(n == 1){
        puts("1");
    }else{
        vis.clear();
        path.clear();
        vis[1] = path[1] = 0;
        long long cur = 1;
        dfs(cur, 0, 0);
        if(vis.find(n) != vis.end()){
            top = 0;
            while(n != 0){
                stk[top ++] = n;
                n = path[n];
            }
            for(int i = top - 1; i >= 0; -- i)
                printf("%d ",stk[i]);
            puts("");
        }else
            puts("-1");
    }
    return 0;
}
