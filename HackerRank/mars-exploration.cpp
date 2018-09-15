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
const int N = 110;
char s[N];

int main(){
    scanf("%s",s);
    int cnt = 0, len = strlen(s);
    for(int i = 0; i < len; i += 3){
        if(s[i] != 'S')
            ++ cnt;
        if(s[i + 1] != 'O')
            ++ cnt;
        if(s[i + 2] != 'S')
            ++ cnt;
    }
    printf("%d\n",cnt);
    return 0;
}
