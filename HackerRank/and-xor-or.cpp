/*
*
* Tag: Data Structure (monotonous stack)
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3000200;
long long stk[N], v, ans;
int top, n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    ans = 0;
    top = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%lld",&v);
        while(top > 0){
            ans = max(ans, (stk[top - 1]^v));
            if(stk[top - 1] >= v){
                -- top;
            }else
                break;
        }
        stk[top ++] = v;
    }
    printf("%lld\n",ans);
    return 0;
}
