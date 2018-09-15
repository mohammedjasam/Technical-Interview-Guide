/*
*
* Tag: Data Structure
* Time: O(n + m)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
int n, m, cnt;
long long stk[2][N], x, sum, u, v;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d%lld",&n,&m,&x);
        sum = 0;
        for(int i = 0; i < n; ++ i)
            scanf("%lld",&stk[0][i]);
        for(int i = 0; i < m; ++ i)
            scanf("%lld",&stk[1][i]);
        int i = 0, j = 0;
        while(i < n && sum + stk[0][i] <= x){
            sum += stk[0][i];
            ++ i;
        }
        cnt = 0;
        while(1){
            while(j < m && sum + stk[1][j] <= x){
                sum += stk[1][j];
                ++ j;
            }
            cnt = max(cnt, i + j);
            if(i == 0)
                break;
            else{
                -- i;
                sum -= stk[0][i];
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
