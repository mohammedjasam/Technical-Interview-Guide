/*
*
* Tag: Implementation
* Time: O(1)
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
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    int ansa = 0, ansb = 0;
    if(a0 > b0)
        ++ ansa;
    else if(a0 < b0)
        ++ ansb;
    if(a1 > b1)
        ++ ansa;
    else if(a1 < b1)
        ++ ansb;
    if(a2 > b2)
        ++ ansa;
    else if(a2 < b2)
        ++ ansb;
    printf("%d %d\n",ansa,ansb);
    return 0;
}
