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
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        long long ans = 0, v;
        int cntone = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; ++ i){
            scanf("%lld",&v);
            ans ^= v;
            if(v <= 1)
                ++ cntone;
        }
        if((cntone == n && ans == 1) || (cntone != n && !ans))
            puts("Second");
        else
            puts("First");
    }
    return 0;
}
