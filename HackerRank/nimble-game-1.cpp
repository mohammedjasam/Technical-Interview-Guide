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
        scanf("%d",&n);
        long long v;
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            scanf("%lld",&v);
            if(v%2)
                ans ^= i;
        }
        if(ans)
            puts("First");
        else
            puts("Second");
    }
    return 0;
}
