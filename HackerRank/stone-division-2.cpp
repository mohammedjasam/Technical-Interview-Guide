/*
*
* Tag: DFS
* Time: O(m*lgn)
* Space: O(m*lgn)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 1100;
int m;
long long n, s[N];
unordered_map<long long, long long> sg;

long long dfs(long long v){
   if(sg.find(v) != sg.end())
       return sg[v];
    long long ans = 0;
    for(int i = 0; i < m && v > s[i]; ++ i){
        if(v%s[i] == 0){
            long long stp = dfs(s[i]);
            stp = 1 + (v/s[i])*stp;
            ans = max(ans, stp);
        }
    }
    sg[v] = ans;
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    scanf("%d",&q);
    while(q --){
        scanf("%lld%d",&n,&m);
        for(int i = 0; i < m; ++ i)
            scanf("%lld",&s[i]);
        sort(s, s+m);
        sg.clear();
        printf("%lld\n",dfs(n));
    }
    return 0;
}
