/*
*
* Tag: Math
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
long long ans;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    long long v = 5;
    ans = 0;
    for(int i = 1; i <= n; ++ i){
        ans += v/2;
        v = (v/2)*3;
    }
    printf("%lld\n",ans);
    return 0;
}
