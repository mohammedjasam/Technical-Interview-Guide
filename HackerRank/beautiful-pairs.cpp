/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 1010;
unordered_map<int,int> dict, adict;
int a[N], b[N];
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    int ans = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&a[i]);
        ++ adict[a[i]];
    }
    for(int i = 0; i < n; ++ i){
        scanf("%d",&b[i]);
        if(adict[b[i]]){
            -- adict[b[i]];
            ++ ans;
        }
    }
    if(ans == n)
        -- ans;
    else{
        ++ ans;
    }
    printf("%d\n",ans);
    return 0;
}
