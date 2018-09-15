/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int s,t,m,n;
long long a, b, u,v;

int main(){
    int ans_a = 0, ans_b = 0;
    scanf("%d%d%lld%lld%d%d",&s,&t,&a,&b,&m,&n);
    for(int i = 0; i < m; ++ i){
        scanf("%lld",&v);
        u = a + v;
        if(u >= s && u <= t)
            ++ ans_a;
    }
    for(int i = 0; i < n; ++ i){
        scanf("%lld",&v);
        u = b + v;
        if(u >= s && u <= t)
            ++ ans_b;
    }
    printf("%d\n%d\n",ans_a,ans_b);
    return 0;
}
