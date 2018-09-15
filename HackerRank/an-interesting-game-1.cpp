/*
*
* Tag: Game Theory
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
int n, v, cur, cnt;

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        cur = cnt = 0;
        for(int i = 0; i < n; ++ i){
            scanf("%d",&v);
            if(v > cur){
                ++ cnt;
                cur = v;
            }
        }
        if(cnt%2 == 1)
            puts("BOB");
        else
            puts("ANDY");
    }
    return 0;
}
