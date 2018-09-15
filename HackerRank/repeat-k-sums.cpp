/*
*
* Tag: DFS
* Time: O(n^k)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 100010;
long long arr[N];
map<long long, int> dict;
int tot, n, k;
long long x, cur;

void calc(int dep, int bnd, int num){
    if(num == 0 || dep + 1 == bnd){
        ++ tot;
        return ;
    }
    for(int i = 0; i <= num; ++ i)
        calc(dep + 1, bnd, num - i);
}

void dfs(int dep, long long sum, int num){
    if(dep == 0)
        sum += num*arr[0];
    
    if(num == 0 || dep == 0){
        -- dict[sum];
        if(dict[sum] == 0)
            dict.erase(sum);
        return ;
    }
    
    for(int i = 0; i <= num; ++ i)
        dfs(dep - 1, sum + i*arr[dep], num - i);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&n,&k);
        tot = 0;
        dict.clear();
        calc(0, n, k);
        
        for(int i = 0; i < tot; ++ i){
            scanf("%lld",&x);
            ++ dict[x];
        }
        
        for(int i = 0; i < n; ++ i){
            cur = dict.begin()->first;
            if(i == 0){
                arr[i] = cur/k;
                -- dict[cur];
                if(dict[cur] == 0)
                    dict.erase(cur);
            }else{
                arr[i] = cur - arr[0]*(k - 1);
                
                for(int j = 1; j <= k; ++ j)
                    dfs(i - 1, arr[i]*j, k - j);
            }
        }
        
        for(int i = 0; i < n; ++ i){
            if(i)
                printf(" ");
            printf("%lld",arr[i]);
        }
        puts("");
    }
    return 0;
}
