/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
char a[N], b[N], c[N];
int abin[N << 2],bbin[N<<2], cbin[N<<2];
int q, k;

inline int hexTobin(char* src, int dest[]){
    int j = 0;
    for(int i = 0; src[i]; ++ i, j += 4){
        int key = src[i] - '0';
        if(src[i] >= 'A')
            key = src[i] - 'A' + 10;
        for(int k = 0; k < 4; ++ k)
            dest[k + j] = (key & (1 << (3 - k))) > 0;
    }
    reverse(dest, dest+j);
    return j;
}

inline int cntOne(int src[], int l, int r){
    int res = 0;
    for(int i = l; i < r; ++ i)
        res += src[i];
    return res;
}

inline char computeHex(int src[], int idx){
    int res = 0;
    for(int i = 0; i < 4; ++ i){
        res |= src[idx+i]?1<<i:0;
    }
    return res > 9?'A'+res-10:res+'0';
}

inline bool assign(int src[], int idx, int toVal){
    bool res = src[idx] > 0;
    src[idx] = toVal;
    return res;
}

inline void binTohex(int src[], char dest[]){
    int lastOnepos = 0;
    for(int i = N<<2; i; -- i){
        if(src[i - 1]){
            lastOnepos = i - 1;
            break;
        }
    }
    int hexlen = 0;
    for(int i = 0; i <= lastOnepos; i += 4){
        dest[hexlen ++] = computeHex(src, i);
    }
    dest[hexlen] = 0;
    reverse(dest, dest + hexlen);
}

int main(){
    scanf("%d",&q);
    while(q --){
        memset(abin, 0, sizeof(abin));
        memset(bbin, 0, sizeof(bbin));
        scanf("%d%s%s%s",&k,a,b,c);
        int alen = hexTobin(a, abin), blen = hexTobin(b, bbin), clen = hexTobin(c, cbin);
        int mustChgInA = cntOne(abin, clen, alen), mustChgInB = cntOne(bbin, clen, blen);
        for(int i = clen; i < alen; ++ i)
            abin[i] = 0;
        for(int i = clen; i < blen; ++ i)
            bbin[i] = 0;
        for(int i = 0; i < clen; ++ i){
            if(!cbin[i]){
                mustChgInA += assign(abin, i, 0);
                mustChgInB += assign(bbin, i, 0);
            }else if (!abin[i] && !bbin[i]) {
                bbin[i] = 1;
                ++mustChgInB;
            }
        }
        int res = mustChgInA + mustChgInB;
        for(int i = clen - 1; i >= 0 && res < k; -- i){
            if(cbin[i]){
                if(abin[i] && bbin[i]){
                    ++ res;
                    abin[i] = 0;
                }else if(abin[i] && !bbin[i]){
                    if(res + 2 <= k){
                        res += 2;
                        abin[i] = 0;
                        bbin[i] = 1;
                    }
                }
            }
        }
        
        if(res > k)
            puts("-1");
        else{
            binTohex(abin, a);
            binTohex(bbin, b);
            printf("%s\n%s\n",a,b);
        }
    }
    return 0;
}
