/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long a, b, c, d, pos;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%lld%lld%lld",&a,&b,&d);
        long long ans = d/b;
        pos = ans*b;
        if(d == pos)
            printf("%lld\n",ans);
        else if((d - pos) == a)
            printf("%lld\n",ans + 1);
        else{
            if(ans){
                c = (ans - 1)*d;
                if(d - c < 2*b){
                    printf("%lld\n",ans + 1);
                    continue;
                }
            }
            printf("%lld\n",ans + 2);
        }
    }
    return 0;
}
