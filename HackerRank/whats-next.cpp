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
using namespace std;
const int N = 15;
int n;
long long arr[N], ans[N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        int len = 0;
        for(int i = 0; i < n; ++ i)
            scanf("%lld",&arr[i]);
        if(n == 1){
            ans[len ++] = 1;
            ans[len ++] = 1;
            if(arr[0] > 1)
                ans[len ++] = arr[0] - 1;
        }else if(n == 2){
            ans[len ++] = 1;
            if(arr[0] == 1)
                ans[len ++] = arr[1] + 1;
            else{
                ans[len ++] = arr[1] + 1;
                ans[len ++] = arr[0] - 1;
            }
        }else{
            if(n%2 == 1){
                for(int i = 0; i < n - 3; ++ i, ++ len)
                    ans[len] = arr[i];
                if(arr[n - 2] == 1){
                    ans[len ++] = arr[n - 3] + 1;
                    ans[len ++] = 1;
                    ans[len ++] = arr[n - 1] - 1;
                }else{
                    ans[len ++] = arr[n - 3];
                    ans[len ++] = arr[n - 2] - 1;
                    ans[len ++] = 1;
                    ans[len ++] = 1;
                    ans[len ++] = arr[n - 1] - 1;
                }
            }else{
                for(int i = 0; i < n - 4; ++ i, ++ len)
                    ans[len] = arr[i];
                if(arr[n - 3] == 1){
                    ans[len ++] = arr[n - 4] + 1;
                    if(arr[n - 2] == 1)
                        ans[len ++] = arr[n - 1] + 1;
                    else{
                        ans[len ++] = arr[n - 1] + 1;
                        ans[len ++] = arr[n - 2] - 1;
                    }
                }else{
                    ans[len ++] = arr[n - 4];
                    ans[len ++] = arr[n - 3] - 1;
                    ans[len ++] = 1;
                    if(arr[n - 2] == 1)
                        ans[len ++] = arr[n - 1] + 1;
                    else{
                        ans[len ++] = arr[n - 1] + 1;
                        ans[len ++] = arr[n - 2] - 1;
                    }
                }
            }
        }
        while(ans[len - 1] == 0) -- len;
        printf("%d\n",len);
        bool isfirst = true;
        for(int i = 0; i < len; ++ i){
            if(!isfirst)
                printf(" ");
            printf("%lld",ans[i]);
            isfirst = false;
        }
        puts("");
    }
    return 0;
}
