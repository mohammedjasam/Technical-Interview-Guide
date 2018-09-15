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
int n, k, v, b;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&k);
    int ans = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        if(i != k)
            ans += v;
    }
    scanf("%d",&b);
    if(ans/2 == b)
        puts("Bon Appetit");
    else
        printf("%d\n",b - ans/2);
    return 0;
}
