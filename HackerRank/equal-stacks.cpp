/*
*
* Tag: HashMap
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
#include <unordered_set>
using namespace std;
const int N = 100100;
unordered_set<int> s[2];
int n1, n2, n3;
int v1[N], v[N];

int main(){
    scanf("%d%d%d",&n1,&n2,&n3);
    for(int i = 0; i < n1; ++ i)
        scanf("%d",&v1[n1 - i - 1]);
    for(int i = 1; i < n1; ++ i)
        v1[i] += v1[i - 1];
    for(int i = 0; i < n2; ++ i){
        scanf("%d",&v[n2 - i - 1]);
    }
    for(int i = 0; i < n2; ++ i){
        if(i)
            v[i] += v[i - 1];
        s[0].insert(v[i]);
    }
    for(int i = 0; i < n3; ++ i){
        scanf("%d",&v[n3 - i - 1]);
    }
    for(int i = 0; i < n3; ++ i){
        if(i)
            v[i] += v[i - 1];
        s[1].insert(v[i]);
    }
    int ans = 0;
    for(int i = n1 - 1; i >= 0; -- i){
        if(s[0].find(v1[i]) != s[0].end() && s[1].find(v1[i]) != s[1].end()){
            ans = v1[i];
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
