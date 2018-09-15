/*
*
* Tag: Data Structure
* Time: O(n)
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
const int N = 200;
int n, v, ans;
unordered_map<int,int> dict;
unordered_map<int,int>::iterator it;

int main(){
    dict.clear();
    ans = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        ++ dict[v];
    }
    for(it = dict.begin(); it != dict.end(); ++ it){
        v = it->first - 1;
        if(dict.find(v) == dict.end())
            v = 0;
        else
            v = dict[v];
        ans = max(ans, it->second + v);
    }
    printf("%d\n",ans);
    return 0;
}
