/*
*
* Tag: Implementation
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
const int N = 100100;
const int M = 30;
char s[N];
bool vis[M];
int n;

int main(){
    scanf("%d",&n);
    while(n --){
        scanf("%s",s);
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = 0; s[i]; ++ i){
            if(!vis[s[i] - 'a']){
                ++ ans;
                vis[s[i] - 'a'] = 1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
