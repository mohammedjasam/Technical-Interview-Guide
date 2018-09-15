/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 6000;
char a[N], b[N];
int lcs, v, ffdp[N][N], bbdp[N][N];
long long uniqstat, uniqcnt;
long long ans;

char hashval(int k){
    if(k >= 0 && k <= 9)
        return (char)(k + '0');
    if(k >= 10 && k <= 35)
        return (char)(k - 10 + 'A');
    if(k >= 36 && k < 62)
        return (char)(k - 36 + 'a');
    return 0;
}

int inthashval(char k){
    if(k >= '0' && k <= '9')
        return (k - '0');
    if(k >='A' && k <= 'Z')
        return (k - 'A') + 10;
    if(k >= 'a' && k <= 'z')
        return (k - 'a') + 36;
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    memset(ffdp, 0, sizeof(ffdp));
    memset(bbdp, 0, sizeof(bbdp));
    ans = lcs = 0;
    scanf("%s%s",a,b);
    int lena = strlen(a), lenb = strlen(b);
    for(int i = 0; i < lena; ++ i){
        for(int j = 0; j < lenb; ++ j){
            if(a[i] == b[j])
                ffdp[i + 1][j + 1] = max(ffdp[i + 1][j + 1], ffdp[i][j] + 1);
            else{
                ffdp[i + 1][j + 1] = max(ffdp[i + 1][j + 1], ffdp[i + 1][j]);
                ffdp[i + 1][j + 1] = max(ffdp[i + 1][j + 1], ffdp[i][j + 1]);
            }
        }
    }
    lcs = ffdp[lena][lenb];
    for(int i = lena - 1; i >= 0; -- i){
        for(int j = lenb - 1; j >= 0; -- j){
            if(a[i] == b[j])
                bbdp[i][j] = max(bbdp[i][j], bbdp[i + 1][j + 1] + 1);
            else{
                bbdp[i][j] = max(bbdp[i][j], bbdp[i + 1][j]);
                bbdp[i][j] = max(bbdp[i][j], bbdp[i][j + 1]);
            }
        }
    }
    for(int i = -1; i < lena; ++ i){
        uniqstat = 0;
        for(int j = 0; j < lenb; ++ j){
            if(ffdp[i + 1][j] + bbdp[i + 1][j + 1] == lcs){
                int v = inthashval(b[j]);
                if((uniqstat&(1L<<v)) == 0){
                    ++ ans;
                    uniqstat |= (1L<<v);
                }
                if(uniqstat == LLONG_MAX)
                    break;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
