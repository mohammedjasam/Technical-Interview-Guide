/*
*
* Tag: Bit Manipulation
* Time: O(lgn)
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
int n, cnt;

int main(){
    scanf("%d",&n);
    cnt = 0;
    int mask = 1, tmp = 0;
    while(mask <= n){
        if((mask&n) != 0)
            ++ tmp;
        else
            tmp = 0;
        cnt = max(cnt, tmp);
        mask <<= 1;
    }
    cnt = max(cnt, tmp);
    printf("%d\n",cnt);
    return 0;
}
