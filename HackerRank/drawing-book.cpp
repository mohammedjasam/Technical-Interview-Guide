/*
*
* Tag: Implementation
* Time: O(1)
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
int n, p, ans;

int main(){
    scanf("%d%d",&n,&p);
    ans = (p%2 == 0?p/2:(p - 1)/2);
    if((n - p)%2 == 0)
        ans = min(ans, (n - p)/2);
    else
        ans = min(ans, (n - p + 1)/2 - 1);
    printf("%d\n",ans);
    return 0;
}
