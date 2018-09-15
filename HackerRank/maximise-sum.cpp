/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
const int M = 100010;
int n;
unsigned long long m;
pair<unsigned long long, int> a[M];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%llu",&n, &m);
        for(int i = 0; i < n; ++ i){
            scanf("%llu",&a[i].first);
            a[i].second = i + 1;
            a[i].first = a[i].first%m;
        }
        unsigned long long ans = a[0].first;
        for(int i = 1; i < n; ++ i){
            a[i].first = (a[i].first + a[i - 1].first)%m;
            ans = max(ans, a[i].first);
        }
        sort(a, a+n);
        unsigned long long minval = ULONG_MAX;
        for(int i = 0; i < n - 1; ++ i){
            if(a[i + 1].second < a[i].second){
                minval = min(minval, a[i + 1].first - a[i].first);
            }
        }
        printf("%llu\n",max(ans, m - minval));
    }
    return 0;
}
