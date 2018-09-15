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
int n, v;
unordered_map<int,int> fun;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d",&v);
        fun[v] = i;
    }
    for(int i = 1; i <= n; ++ i)
        printf("%d\n",fun[fun[i]]);
    return 0;
}
