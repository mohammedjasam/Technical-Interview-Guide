/*
*
* Tag: Math
* Time: O(nm)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 300;
int n;
int dict[N], arr[N], sortarr[N];

long long factor(int n){
    long long res = 1;
    for(int i = 2; i <= n; ++ i)
        res *= i;
    return res;
}

bool check(){
    for(int i = 0; i < n; ++ i){
        if(arr[i] != sortarr[i])
            return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&arr[i]);
        sortarr[i] = arr[i];
        ++ dict[arr[i]];
    }
    sort(sortarr, sortarr + n);
    if(check()){
        puts("0.000000");
    }else{
        long long ans = factor(n);
        for(int i = 0; i < N; ++ i){
            if(dict[i] > 0){
                ans /= factor(dict[i]);
            }
        }
        printf("%lld.000000\n",ans);
    }
    return 0;
}
