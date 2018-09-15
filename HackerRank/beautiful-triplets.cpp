/*
*
* Tag: Binary Search
* Time: O(nlgn)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10100;
int a[N], n, d;

int bsearch(int l, int r, int v){
    while(l <= r){
        int mid = (l + r)>>1;
        if(a[mid] == v)
            return mid;
        else if(a[mid] < v)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&d);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&a[i]);
    int ans = 0;
    for(int i = 0; i < n - 2; ++ i){
        int idx = bsearch(i + 1, n - 1, a[i] + d);
        if(idx != -1){
            idx = bsearch(idx + 1, n - 1, a[i] + 2*d);
            ans += idx==-1?0:1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
