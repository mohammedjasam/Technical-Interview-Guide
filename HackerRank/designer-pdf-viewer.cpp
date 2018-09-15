/*
*
* Tag: Math
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
int h[N];
char s[N];

int main(){
    for(int i = 0; i < 26; ++ i)
        scanf("%d",&h[i]);
    scanf("%s",s);
    int maxh = 0, w = strlen(s);
    for(int i = 0; i < w; ++ i)
        maxh = max(maxh, h[s[i] - 'a']);
    printf("%d\n",maxh*w);
    return 0;
}
