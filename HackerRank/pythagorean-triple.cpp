/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int a;

int main() {
    scanf("%d",&a);
    long long m, n, v;
    printf("%d ",a);
    if(a%2 == 0){
        m = a/2, n = 1;
        printf("%lld %lld\n", m*m - n*n, m*m + n*n);
    }else{
        n = (a - 1)/2;
        m = n + 1;
        printf("%lld %lld\n", 2*m*n, m*m + n*n);
    }
    return 0;
}
