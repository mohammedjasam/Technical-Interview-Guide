/*
*
* Tag: Implementation
* Time: O(n*(n/k))
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int arr[N];
int n, k;

int main() {
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&arr[i]);
    }
    int ans = 0, pcnt = 1;
    for(int i = 0; i < n; ++ i){
        int lstpbcnt = 0, pbcnt = 0, pval = arr[i];
        while(pbcnt < pval){
            pbcnt += min(k, arr[i]);
            arr[i] -= k;
            if(lstpbcnt < pcnt && pcnt <= pbcnt){
                ++ ans;
            }
            lstpbcnt = pbcnt;
            ++ pcnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}
