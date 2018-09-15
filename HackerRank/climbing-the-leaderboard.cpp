/*
*
* Tag: Data Structure
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
#include <map>
using namespace std;
int n, m, u, v;
map<int,int> dict;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        dict[v] = 0;
    }
    int rnk = dict.size(), id = 1;
    map<int,int>::iterator it;
    for(it = dict.begin(); it != dict.end(); ++ it, -- rnk)
        dict[it->first] = rnk;
    scanf("%d",&m);
    for(int i = 0; i < m; ++ i){
        scanf("%d",&v);
        if(dict.find(v) != dict.end())
            printf("%d\n",dict[v]);
        else{
            it = dict.upper_bound(v);
            if(it == dict.end())
                puts("1");
            else
                printf("%d\n",it->second + 1);
        }
    }
    return 0;
}
