/*
*
* Tag: Math
* Time: O(lgt)
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
long long t, bnd, pret, curt, ans;

int main(){
    scanf("%lld",&t);
    bnd = 3;
    curt = 3;
    pret = 0;
    while(curt < t){
        pret = curt;
        bnd <<= 1;
        curt += bnd;
    }
    printf("%lld\n",bnd - (t-pret) + 1);
    return 0;
}
