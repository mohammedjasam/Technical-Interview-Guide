/*
*
* Tag: Hash
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
const int N = 300;
int col[N], n, c, bnd, ans;

int main(){
    scanf("%d",&n);
    ans = bnd = 0;
    memset(col, 0, sizeof(col));
    for(int i = 0; i < n; ++ i){
        scanf("%d",&c);
        ++ col[c];
        bnd = max(bnd, c);
    }
    for(int i = 1; i <= bnd; ++ i){
        ans += (col[i]/2);
    }
    printf("%d\n",ans);
    return 0;
}
