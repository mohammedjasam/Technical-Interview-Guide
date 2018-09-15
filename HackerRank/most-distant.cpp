/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
pair<long long,long long> x, y;
int n;
long long u, v;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    x.first = INT_MAX, x.second = INT_MIN;
    y.first = INT_MAX, y.second = INT_MIN;
    for(int i = 0; i < n; ++ i){
        scanf("%lld%lld",&u,&v);
        if(v == 0){
            x.first = min(x.first, u);
            x.second = max(x.second, u);
        }
        if(u == 0){
            y.first = min(y.first, v);
            y.second = max(y.second, v);
        }
    }
    double ans = INT_MIN;
    ans = max(ans, (double)x.second - x.first);
    ans = max(ans, (double)y.second - y.first);
    ans = max(ans, sqrt((double)max( max(x.first*x.first + y.first*y.first, x.first*x.first + y.second*y.second), max(x.second*x.second + y.first*y.first, x.second*x.second + y.second*y.second) )) );
    printf("%.6lf\n",ans);
    return 0;
}
