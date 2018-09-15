/*
*
* Tag: String
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
const int N = 30;
const int M = 11000;
int dict[2][N];
char a[M], b[M];

int main(){
    scanf("%s%s",a,b);
    memset(dict, 0, sizeof(dict));
    for(int i = 0; a[i]; ++ i)
        ++ dict[0][a[i] - 'a'];
    for(int i = 0; b[i]; ++ i)
        ++ dict[1][b[i] - 'a'];
    int ans = 0;
    for(int i = 0; i < N; ++ i)
        ans += abs(dict[0][i] - dict[1][i]);
    printf("%d\n",ans);
    return 0;
}
