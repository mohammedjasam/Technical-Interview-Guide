/*
*
* Tag: Implementation
* Time: O(n^2)
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
const int N = 300;
int arr[N], n, k;

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&arr[i]);
    int cnt = 0;
    for(int i = 0; i < n - 1; ++ i){
        for(int j = i + 1; j < n; ++ j){
            if((arr[i] + arr[j])%k == 0)
                ++ cnt;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
