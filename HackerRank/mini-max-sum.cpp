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
const int N = 10;
long long sum, minval, maxval, v;

int main(){
    sum = 0;
    minval = LLONG_MAX, maxval = LLONG_MIN;
    for(int i = 0; i < 5; ++ i){
        scanf("%lld",&v);
        sum += v;
        minval = min(minval, v);
        maxval = max(maxval, v);
    }
    printf("%lld %lld\n",sum-maxval, sum - minval);
    return 0;
}
