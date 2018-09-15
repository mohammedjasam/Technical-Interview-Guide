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
long long n, cnt;

int main(){
    scanf("%lld",&n);
    long long v = 1, ans = 0;
    cnt = 0;
    while(v <= n){
        if((v&n) == 0)
            ++ cnt;
        v <<= 1;
    }
    ans = (1L<<cnt);
    printf("%lld\n",ans);
    return 0;
}
