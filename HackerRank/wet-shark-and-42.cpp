/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MOD = 1000000007;
long long s;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%lld",&s);
        long long ans = 0;
        while(s > 420){
            ans = (ans + s/420*420)%MOD;
            s = s - (s/420*200);
        }
        long long i = 0;
        while(s > 0){
            ++ i;
            ++ ans;
            if(i%2 == 0 && i%42 !=0 )
                -- s;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
