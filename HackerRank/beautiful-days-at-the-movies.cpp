/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long v, k, s, t, dif;
int ans;

long long revs(long long v){
    long long res = 0;
    while(v > 0){
        res = res*10 + (v%10);
        v /= 10;
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ans = 0;
    scanf("%lld%lld%lld",&s,&t,&k);
    for(v = s; v <= t; ++ v){
        dif = abs(v - revs(v));
        ans += (dif%k == 0);
    }
    printf("%d\n",ans);
    return 0;
}
