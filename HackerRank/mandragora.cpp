/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 111000;
long long h[N], s;
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        s = 1;
        for(int i = 0; i < n; ++ i)
            scanf("%lld",&h[i]);
        sort(h, h + n);
        for(int i = n - 2; i >= 0; -- i)
            h[i] += h[i + 1];
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; ++ i){
            ans = max(ans, s*h[i]);
            ++ s;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
