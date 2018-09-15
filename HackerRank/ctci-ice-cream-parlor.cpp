/*
*
* Tag: Data Structure (Hash)
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
const int N = 110000;
map<int,int> dict;
map<int,int>::iterator it;
int arr[N], btree[N], n, bnd;
long long ans;

int lowbit(int x){
    return x&-x;
}

void update(int sta){
    for(int i = sta; i <= bnd; i += lowbit(i)){
        ++ btree[i];
    }
}

int sumup(int bnd){
    int sum = 0;
    for(int i = bnd; i > 0; i -= lowbit(i))
        sum += btree[i];
    return sum;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        dict.clear();
        memset(btree, 0, sizeof(btree));
        for(int i = 0; i < n; ++ i){
            scanf("%d",&arr[i]);
            dict[arr[i]] = 0;
        }
        int cnt = 1;
        for(it = dict.begin(); it != dict.end(); ++ it){
            dict[it->first] = cnt ++;
        }
        bnd = cnt - 1;
        ans = 0;
        for(int i = n - 1; i >= 0; -- i){
            ans += sumup(dict[arr[i]] - 1);
            update(dict[arr[i]]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
