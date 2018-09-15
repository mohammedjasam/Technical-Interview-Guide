/*
*
* Tag: Bit Manipulation
* Time: O(n^2)
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
int n, k;

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&n,&k);
        int ans = 0;
        for(int i = 1; i < n; ++ i){
            for(int j = i + 1; j <= n; ++ j){
                int v = i&j;
                if(v < k)
                    ans = max(ans, v);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
