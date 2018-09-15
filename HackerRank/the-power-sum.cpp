/*
*
* Tag: DP
* Time: O(nm)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 150;
const int M = 1100;
long long multi[N];
int x, n, num, dp[M];

void init(){
    multi[1] = 1;
    num = 2;
    for(long long i = 2; i <= 100; ++ i ){
        long long res = i;
        for(int j = 2; j <= n; ++ j){
            res *= i;
        }
        if(res > x)
            break;
        multi[num ++] = res;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&x,&n);
    init();
    for(int i = 1; i < num; ++ i){
        for(int j = x; j >= multi[i]; -- j)
            dp[j] += dp[j - multi[i]];
    }
    printf("%d\n",dp[x]);
    return 0;
}
