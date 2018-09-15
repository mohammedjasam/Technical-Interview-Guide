/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long x, y, z, b, w;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%lld%lld%lld%lld%lld",&b,&w,&x,&y,&z);
        if(x + z < y)
            printf("%lld\n",(b+w)*x + w*z);
        else if(y + z < x)
            printf("%lld\n",(b+w)*y + b*z);
        else
            printf("%lld\n",b*x + w*y);
    }
    return 0;
}
