/*
*
* Tag: Math
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
const int N = 300;
char s[N];
int cnt[N], len, m;
long long n;

int main(){
    memset(cnt, 0, sizeof(cnt));
    scanf("%s%lld",s,&n);
    for(int i = 0; s[i]; ++ i){
        if(s[i] == 'a'){
            if(!i)
                cnt[i] = 1;
            else
                cnt[i] = cnt[i - 1] + 1;
        }else{
            if(!i)
                cnt[i] = 0;
            else
                cnt[i] = cnt[i - 1];
        }
    }
    len = strlen(s);
    long long ans = n/len, m = n%len, tmp = 0;
    if(m)
        tmp = cnt[m - 1];
    ans = ans*cnt[len - 1] + tmp;
    printf("%lld\n",ans);
    return 0;
}
