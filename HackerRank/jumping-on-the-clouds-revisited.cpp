/*
*
* Tag: Implementation
* Time: LCM(k, n)
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

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    int ans = 100, cur = 0, cnt = 1;
    while(cur || cnt < 2){
        cur = (cur + k)%n;
        if(c[cur])
            ans -= 2;
        -- ans;
        if(!cur)
            ++ cnt;
    }
    printf("%d\n",ans);
    return 0;
}
