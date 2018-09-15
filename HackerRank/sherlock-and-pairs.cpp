/*
*
* Tag: Hash
* Time: O(max(a[i])) where i is between [0 ... n - 1]
* Space: O(max(a[i]))
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
const int M = 1000100;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        vector<long long> rec;
        rec.resize(M);
        long long maxval = -2;
        for(int i = 0; i < n; i ++){
            long long a;
            scanf("%lld",&a);
            rec[a] ++;
            maxval = max(a, maxval);
        }
        long long ans = 0;
        for(int i = 1; i <= maxval; i ++){
            if(rec[i]){
                ans += rec[i]*(rec[i] - 1);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
