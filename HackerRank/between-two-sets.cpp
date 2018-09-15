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
const int N = 200;
int a[N], b[N], n, m, v, u, bnd, c;
int p[N], pnum[N], num;

void init(){
    num = 0;
    bool isPrime = false;
    for(int i = 2; i < N; ++ i){
        isPrime = true;
        for(int j = 2; j*j <= i; ++ j){
            if(i%j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            p[num ++] = i;
    }
}

void getPrimeFactor(int v){
    int cnt = 0;
    for(int i = 0; i < num && p[i] <= v; ++ i){
        cnt = 0;
        while(v%p[i] == 0){
            v /= p[i];
            ++ cnt;
        }
        pnum[i] = max(pnum[i], cnt);
    }
}

void getMultiValue(){
    u = 1;
    for(int i = 0; i < num; ++ i){
        while(pnum[i]){
            u *= p[i];
            -- pnum[i];
        }
    }
}

int main(){
    init();
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        getPrimeFactor(v);
    }
    getMultiValue();
    bnd = 0;
    for(int i = 0; i < m; ++ i){
        scanf("%d",&b[i]);
        bnd = max(bnd, b[i]);
    }
    c = 1;
    int ans = 0, tmp = 0;
    bool isDiv = false;
    for(; c*u <= bnd; ++ c){
        isDiv = true;
        tmp = c*u;
        for(int i = 0; i < m; ++ i){
            if(b[i]%tmp != 0){
                isDiv = false;
                break;
            }
        }
        if(isDiv)
            ++ ans;
    }
    printf("%d\n",ans);
    return 0;
}
