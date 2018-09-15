/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int arr[N], n;

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&arr[i]);
    sort(arr, arr + n);
    int ans = INT_MAX;
    for(int i = 1; i < n; ++ i)
        ans = min(ans, arr[i] - arr[i - 1]);
    printf("%d\n",ans);
    return 0;
}
