/*
*
* Tag: Binary Index Tree
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N], b[N];
int n;

void init(){
    memset(a, 0, sizeof(a));
}

int lowbit(int x){
    return x&-x;
}

void update(int idx, int n){
    for(int i = idx; i <= n; i += lowbit(i))
        a[i] += 1;
}

int sum(int idx){
    int res = 0;
    for(int i = idx; i > 0; i -= lowbit(i))
        res += a[i];
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    scanf("%d",&T);
    while(T --){
        init();
        scanf("%d",&n);
        int ans = 0, num = 0;
        for(int i = 0; i < n; ++ i){
            int v;
            scanf("%d",&v);
            if(v - 1 != i)
                b[num ++] = v;
        }
        for(int i = num - 1; i >= 0; -- i){
            ans += sum(b[i]);
            update(b[i], n);
        }
        if(ans%2 == 0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
