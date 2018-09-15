/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int c[N];
int n, k, p, t;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    scanf("%d%d",&n,&k);
    int ans = 0, cnt = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d%d",&p, &t);
        if(!t)
            ans += p;
        else
            c[cnt ++] = p;
    }
    sort(c, c+cnt, greater<int>());
    int i = 0;
    for(; i < k || i < cnt; ++ i){
        if(i < k)
            ans += c[i];
        else
            ans -= c[i];
    }
    printf("%d\n",ans);
    return 0;
}
