/*
*
* Tag: Greedy
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
const int N = 110;
int n;
char s[N];

int main(){
    scanf("%d",&n);
    scanf("%s",s);
    int ans = 0;
    for(int i = 0; i < n - 2; ++ i){
        if(s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0'){
            if(s[i + 3] == '1' && s[i + 4] == '0'){
                s[i+2] = '1';
            }else{
                s[i] = '1';
            }
            ++ ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
