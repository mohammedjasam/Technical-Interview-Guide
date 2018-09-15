/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int n;
        scanf("%d",&n);
        vector<long long> recd;
        recd.resize(n);
        long long sum = 0;
        for(int i = 0; i < n; i ++){
            long long inpt;
            scanf("%lld",&inpt);
            if(i == 0)
                recd[0] = inpt;
            else
                recd[i] = recd[i - 1] + inpt;
        }
        bool flag = false;
        for(int i = 0; i < n; i ++){
            long long left = 0, right = 0;
            if(i == 0)
                left = 0;
            else
                left = recd[i - 1];
            if(i == n - 1)
                right = 0;
            else
                right = recd[n - 1] - recd[i];
            if(left == right){
                flag = true;
                break;
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
