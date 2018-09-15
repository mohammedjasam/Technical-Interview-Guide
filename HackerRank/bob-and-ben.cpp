/*
*
* Tag: Game Theory
* Time: O(n)
* Space: O(1)
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, ans, u, v;

int main(){
    int T;
    scanf("%d",&T);
    while (T --){
        scanf("%d",&n);
        ans = 0;
        for(int i = 0; i < n; ++ i){
            scanf("%d%d",&u,&v);
            if ( u == 1) ans^=1;
            else if (u > 2){
                if (u%2==1) ans^=1;
                else ans^=2;
            }
        }
        if (ans) 
            puts("BOB");
        else 
            puts("BEN");
    }
}
