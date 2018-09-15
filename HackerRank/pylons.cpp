/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
int arr[N], k, n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&k);
    bool hasOne = false;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&arr[i]);
        hasOne |= arr[i];
    }
    if(!hasOne){
        puts("-1");
        return 0;
    }else if(n <= k){
        puts("1");
        return 0;
    }
    int ans = 0, bnd = k - 1, cur = 0, prebnd = -1;
    for(; bnd < n;){
        cur = bnd;
        while(cur > prebnd && !arr[cur]){
            -- cur;
        }
        if(cur <= prebnd){
            ans = -1;
            break;
        }
        ++ ans;
        prebnd = cur;
        bnd = cur + 2*k - 1 < n? cur + 2*k - 1 : cur + k - 1 >= n - 1? n : n - 1;
    }
    printf("%d\n",ans);
    return 0;
}
