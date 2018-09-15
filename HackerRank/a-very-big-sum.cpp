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
long long sum;
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sum = 0;
    scanf("%d",&n);
    long long v;
    for(int i = 0; i < n; ++ i){
        scanf("%lld",&v);
        sum += v;
    }
    printf("%lld\n",sum);
    return 0;
}
