/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long x;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%lld",&x);
        long long ans = 0, mask = 1;
        while(mask < x){
            if((mask&x) == 0){
                ans += mask;
            }
            mask <<= 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
