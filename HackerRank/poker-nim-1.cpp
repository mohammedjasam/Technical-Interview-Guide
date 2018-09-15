/*
*
* Tag: Game
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        long long ans = 0, v;
        scanf("%d%d",&n,&k);
        for(int i = 0; i < n; ++ i){
            scanf("%lld",&v);
            ans ^= v;
        }
        if(ans)
            puts("First");
        else
            puts("Second");
    }
    return 0;
}
