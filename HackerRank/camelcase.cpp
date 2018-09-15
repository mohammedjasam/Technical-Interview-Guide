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
char s[N];

int main(){
    scanf("%s",s);
    int ans = 1;
    for(int i = 0; s[i]; ++ i){
        if(s[i] >= 'A' && s[i] <= 'Z')
            ++ ans;
    }
    printf("%d\n",ans);
    return 0;
}
