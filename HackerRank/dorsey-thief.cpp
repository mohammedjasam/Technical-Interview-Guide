/*
*
* Tag: DP
* Time: O(nx)
* Space: O(x)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 6000;
const int M = 1100000;
long long dp[N];
long long v[M][2];
int n, x;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&x);
    for(int i = 0; i < n; ++ i)
        scanf("%lld%lld",&v[i][0],&v[i][1]);
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++ i){
        for(int j = x; j >= v[i][1]; -- j){
            if(dp[j - v[i][1]] || j == v[i][1])
                dp[j] = max(dp[j], dp[j - v[i][1]] + v[i][0]);
        }
    }
    if(!dp[x])
        puts("Got caught!");
    else
        printf("%lld\n",dp[x]);
    return 0;
}
