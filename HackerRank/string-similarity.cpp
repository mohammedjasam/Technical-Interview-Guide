/*
*
* Tag: String (Suffix Array)
* Time: O(nlgn)
* Space: O(n)
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
//#include <unordered_map>
using namespace std;
const int N = 20;
const int M = 1000005;
const int MOD = 10037;
int wa[M], wb[M], wc[M], wv[M];
char s[M];
int rmq[M], best[N][M], mm[M], ranks[M], h[M];
int r[M], sa[M];

int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m){
    int *x = wa, *y = wb, *t;
    int j, p;
    for (int i = 0; i < m;  ++ i) {
        wc[i] = 0;
    }
    for (int i = 0; i < n; ++ i) {
        ++ wc[x[i] = r[i]];
    }
    for (int i = 1; i < m; ++ i) {
        wc[i] += wc[i - 1];
    }
    for (int i = n - 1; i >= 0; -- i) {
        sa[-- wc[x[i]]] = i;
    }
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        int i;
        for (p = 0, i = n - j; i < n; ++ i) {
            y[p ++] = i;
        }
        for (i = 0; i < n; ++ i) {
            if (sa[i] >= j) {
                y[p ++] = sa[i] - j;
            }
        }
        for (i = 0; i < n; ++ i) {
            wv[i] = x[y[i]];
        }
        for (i = 0; i < m; ++ i) {
            wc[i] = 0;
        }
        for (i = 0; i < n; ++ i) {
            ++ wc[wv[i]];
        }
        for (i = 1; i < m; ++ i) {
            wc[i] += wc[i - 1];
        }
        for (i = n - 1; i >= 0; -- i) {
            sa[--wc[wv[i]]] = y[i];
        }
        for (t = x, x= y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++ i) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)?p - 1 : p ++;
        }
    }
    return ;
}

void calheight(int *r, int *sa, int n){
    int i, j, k = 0;
    for (i = 1; i <= n; ++ i) {
        ranks[sa[i]] = i;
    }
    for (i = 0; i < n; h[ranks[i ++]] = k) {
        for (k?k--:0, j = sa[ranks[i] - 1]; r[i + k] == r[j + k]; ++ k) ;
    }
    return ;
}


int main(){
    int T;
    scanf("%d",&T);
    while (T --) {
        scanf("%s",s);
        int n = strlen(s);
        memset(r, 0, sizeof(r));
        memset(ranks, 0, sizeof(ranks));
        for (int i = 0; i < n; ++ i) {
            r[i] = (int)s[i];
        }
        da(r, sa, n + 1, 256);
        calheight(r, sa, n);
        long long ans = 0, minval = LLONG_MAX;
        int id = ranks[0];
        for(int i = id; i >= 0; -- i){
            minval = min(minval, (long long)h[i]);
            ans += minval;
        }
        minval = LLONG_MAX;
        for(int i = id + 1; i <= n; ++ i){
           minval = min(minval, (long long)h[i]);
            ans += minval; 
        }
        ans += (long long)strlen(s);
        printf("%lld\n",ans);
    }
    return 0;
}
