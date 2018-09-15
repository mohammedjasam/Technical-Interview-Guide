/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int cake[N], n;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&cake[i]);
    sort(cake, cake + n, greater<int>());
    long long ans = 0, mask = 1;
    for(int i = 0; i < n; ++ i, mask <<= 1){
        ans += mask*cake[i];
    }
    printf("%lld\n",ans);
    return 0;
}
