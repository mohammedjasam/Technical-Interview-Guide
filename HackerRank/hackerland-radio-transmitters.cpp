/*
*
* Tag: Greedy
* Time: O(nlgn)
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
const int N = 111000;
int x[N], n, k;

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&x[i]);
    sort(x, x + n);
    int sta = x[0], ans = 0;
    bool isChange = false;
    for(int i = 1; i < n; ++ i){
        if(i == n - 1 || x[i] - sta > k){
            sta = x[i];
            ++ ans;
            continue;
        }
        ++ ans;
        isChange = false;
        while(i < n && x[i] - sta <= k)
            ++ i, isChange = true;
        sta = x[i - 1];
        if(!isChange){
            sta = x[i];
            continue;
        }
        while(i < n && x[i] - sta <= k)
            ++ i;
        sta = x[i];
        -- i;
    }
    if(n == 1)
        ++ ans;
    printf("%d\n",ans);
    return 0;
}
