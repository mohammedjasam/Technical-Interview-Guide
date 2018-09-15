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
        int ans = 0, v;
        for(int i = 0; i < n; ++ i){
            scanf("%d",&v);
            ans ^= v;
        }
        if(ans)
            puts("First");
        else
            puts("Second");
    }
    return 0;
}
