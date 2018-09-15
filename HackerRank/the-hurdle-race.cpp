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
int n, k, v, ans;

int main(){
    scanf("%d%d",&n,&k);
    ans = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        ans = max(ans, max(0, v - k));
    }
    printf("%d\n",ans);
    return 0;
}
