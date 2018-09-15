/*
*
* Tag: Math
* Time: O(k)
* Space: O(k)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int cntk[N];
int n, a, k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int ans = 0;
    scanf("%d%d",&n,&k);
    memset(cntk, 0, sizeof(cntk));
    for(int i = 0; i < n; ++ i){
        scanf("%d",&a);
        ++ cntk[(a%k)];
    }
    for(int i = 0; i <= k/2; ++ i){
        if((!i || i*2 == k) && cntk[i])
            ++ ans;
        else
            ans += max(cntk[i], cntk[k - i]);
    }
    printf("%d\n",ans);
    return 0;
}
