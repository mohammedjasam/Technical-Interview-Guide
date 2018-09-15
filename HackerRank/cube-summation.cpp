#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
long long C[N][N][N], cur[N][N][N];
int n, m;

int lowbit(int x){
    return x&(-x);
}

long long sum(int x, int y, int z){
    long long ans = 0;
    for(int i = x; i > 0; i -= lowbit(i)){
        for(int j = y; j > 0; j -= lowbit(j)){
            for(int k = z; k > 0; k -= lowbit(k)){
                ans += C[i][j][k];
            }
        }
    }
    return ans;
}

void add(int x, int y, int z, long long d){
    for(int i = x; i <= n; i += lowbit(i)){
        for(int j = y; j <= n; j += lowbit(j)){
            for(int k = z; k <= n; k += lowbit(k)){
                C[i][j][k] += d;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&n,&m);
        memset(C, 0, sizeof(C));
        memset(cur, 0, sizeof(cur));
        while(m --){
            char op[N];
            scanf("%s",op);
            if(op[0] == 'U'){
                int x, y, z, k;
                scanf("%d%d%d%d",&x,&y,&z,&k);
                add(x, y, z, k - cur[x][y][z]);
                cur[x][y][z] = k;
            }else{
                int x1, y1, z1, x2, y2, z2;
                scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
                printf("%lld\n",sum(x2,y2,z2)-sum(x1-1,y2,z2)-sum(x2,y1-1,z2)-sum(x2,y2,z1-1)+sum(x1-1,y1-1,z2)+sum(x1-1,y2,z1-1)+sum(x2,y1-1,z1-1)-sum(x1-1,y1-1,z1-1));
            }
        }
    }
    return 0;
}
