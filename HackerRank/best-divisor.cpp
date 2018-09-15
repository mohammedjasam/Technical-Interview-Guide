/*
*
* Tag: Math
* Time: O(n^0.5)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, ans, maxdiv, maxsum;

int calc(int v){
    int res = 0,tmp = v;
    while(v){
        res += (v%10);
        v /= 10;
    }
    return res;
}

void solve(){
    for(int i = 1; i*i <= n; ++ i){
        if(n%i == 0){
            int sum = calc(i);
            if(sum > maxsum){
                maxsum = sum;
                ans = i;
            }else if(sum == maxsum){
                ans = min(ans, i);
            }
            sum = calc(n/i);
            if(sum > maxsum){
                maxsum = sum;
                ans = n/i;
            }else if(sum == maxsum){
                ans = min(ans, n/i);
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    ans = maxsum = 1;
    solve();
    printf("%d\n",ans);
    return 0;
}
