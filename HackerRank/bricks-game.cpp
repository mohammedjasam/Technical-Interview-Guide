/*
*
* Tag: DP
* Time Complexity: O(n)
* Space Complexity: O(n) (O(1) is the bes
*
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        int n;
        scanf("%d",&n);
        vector<long long> arr(n);
        for(int i = 0; i < n; i ++)
            scanf("%lld",&arr[i]);
        vector<long long> dp(n), sum(n);
        if(n <= 3){
            dp[n - 1] = arr[n - 1];
            for(int i = n - 2; i >= 0; -- i)
                dp[i] = dp[i + 1] + arr[i];
        }else{
            sum[n - 1] = arr[n - 1];
            for(int i = n - 2; i >= 0; -- i){
                sum[i] = sum[i + 1] + arr[i];
            }
            dp[n - 1] = arr[n - 1];
            for(int i = n - 2; i >= n - 3; -- i){
                dp[i] = sum[i];
            }
            for(int i = n - 4; i >= 0; -- i){
                long long minval = dp[i + 3];
                minval = min(minval, dp[i + 2]);
                minval = min(minval, dp[i + 1]);
                dp[i] = sum[i] - minval;
            }
        }
        printf("%lld\n",dp[0]);
    }
    return 0;
}
