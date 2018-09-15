/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
bool vis[N], flag;
int n, k, ans[N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&n,&k);
        memset(vis, 0, sizeof(vis));
        flag = true;
        int cnt = 0;
        if((k<<1) > n || (k && n%k)){
            puts("-1");
            continue;
        }
        for(int i = 1; i <= n; ++ i){
            ans[i] = i;
        }
        for(int i = 1; i <= n; ++ i){
            if(vis[i])
                continue;
            if(i + k > n){
                flag = false;
                break;
            }
            swap(ans[i], ans[i + k]);
            vis[i] = vis[i + k] = 1;
        }
        if(!flag){
            puts("-1");
            continue;
        }
        for(int i = 1; i <= n; ++ i)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
