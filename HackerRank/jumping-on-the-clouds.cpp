/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
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
const int N = 110;
int n;
bool cld[N];
int dp[N];

int main(){
    scanf("%d",&n);
    int c[2], v;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&cld[i]);
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(int i = 1; i < n; ++ i){
        if(!cld[i - 1])
            dp[i] = min(dp[i - 1] + 1, dp[i]);
        if(i >= 2 && !cld[i - 2])
            dp[i] = min(dp[i - 2] + 1, dp[i]);
    }
    printf("%d\n",dp[n - 1]);
    return 0;
}
