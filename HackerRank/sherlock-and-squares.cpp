/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int a,b;
        scanf("%d%d",&a,&b);
        int sa = sqrt(a), sb=sqrt(b);
        int ans = sb - sa;
        if(sa*sa == a)
            ans ++;
        printf("%d\n",ans);
    }
    return 0;
}
