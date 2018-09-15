/*
*
* Tag: Math
* Time: O(nlgm)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110000;
long long arr[N], gcdarr[N];
int n;

long long gcd(long long a, long long b){
    return b == 0? a : gcd(b, a%b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    long long ans = 0, tmpgcd = arr[n - 1], curgcd;
    for(int i = 0; i < n; ++ i)
        scanf("%lld",&arr[i]);
    if(n == 1){
        ans = arr[0];
        while(arr[0]%ans == 0) ++ ans;
    }else{
        gcdarr[0] = arr[0];
        for(int i = 1; i < n; ++ i)
            gcdarr[i] = gcd(gcdarr[i - 1], arr[i]);
        ans = 0, tmpgcd = arr[n - 1];
        for(int i = n - 1; i >= 0; -- i){
            if(i == 0){
                ans = tmpgcd;
            }else if(i == n - 1){
                if(arr[n - 1]%gcdarr[n - 2] != 0){
                    ans = gcdarr[n - 2];
                    break;
                }
            }else{
                tmpgcd = gcd(tmpgcd, arr[i + 1]);
                curgcd = gcd(gcdarr[i - 1], tmpgcd);
                if(arr[i]%curgcd != 0){
                    ans = curgcd;
                    break;
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
