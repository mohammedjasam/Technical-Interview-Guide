/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200;
int v, cnt[N], maxcnt;
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    maxcnt = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        ++ cnt[v];
        maxcnt = max(maxcnt, cnt[v]);
    }
    printf("%d\n",n - maxcnt);
    return 0;
}
