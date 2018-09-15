/*
*
* Tag: Greedy
* Time: O(nlgn)
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
const int N = 120;
int n, arr[N], mc[N], v;

bool check(){
    sort(arr, arr + n);
    sort(mc, mc + n);
    for(int i = 0; i < n; ++ i){
        if(arr[i] != mc[i])
            return false;
    }
    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        memset(arr, 0, sizeof(arr));
        memset(mc, 0, sizeof(mc));
        scanf("%d",&n);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                scanf("%d",&v);
                mc[j] += v;
                arr[i] += v;
            }
        }
        if(check())
            puts("Possible");
        else
            puts("Impossible");
    }
    return 0;
}
