/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int n, ne;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long nv = 1;
    long long sd = 0;
    long long dtc = 0;
    long long diam = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d",&ne);
        long long nnv = nv * 4 + 2;
        long long nsd = 4 * sd + 4 * dtc * (2 + 3 * nv % MOD) % MOD + 4 * ne * nv % MOD * (nv * 3 + 2) % MOD +
            ne * (2 * nv + 1) % MOD * (2 * nv + 1) % MOD;
        long long ndtc = 4 * dtc + 8 * ne * nv % MOD + 3 * ne + (3 * nv + 2) * diam % MOD;
        long long ndiam = 2 * diam + 3 * ne;
        nv = nnv % MOD;
        sd = nsd % MOD;
        dtc = ndtc % MOD;
        diam = ndiam % MOD;
    }
    printf("%lld\n",sd);
    return 0;
}
