/*
*
* Tag: Math
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
const int N = 1000100;
int n, m;
int pos[N];

int main(){
    scanf("%d%d",&n,&m);
    int ans = 0;
    for(int i = 0; i < m; ++ i)
        scanf("%d",&pos[i]);
    sort(pos, pos + m);
    for(int i = 1; i < m; ++ i)
        ans = max(ans, (pos[i] - pos[i - 1])/2);
    if(pos[m - 1] < n - 1)
        ans = max(ans, n - 1 - pos[m - 1]);
    if(pos[0] > 0)
        ans = max(ans, pos[0]);
    printf("%d\n",ans);
    return 0;
}
