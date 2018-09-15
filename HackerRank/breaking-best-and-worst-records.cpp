/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int n, v, maxcnt, mincnt, minscr, maxscr;

int main(){
    scanf("%d",&n);
    maxcnt = mincnt = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        if(i == 0){
            minscr = maxscr = v;
        }else{
            if(v < minscr)
                ++ mincnt;
            else if(v > maxscr)
                ++ maxcnt;
            minscr = min(minscr, v);
            maxscr = max(maxscr, v);
        }
    }
    printf("%d %d\n",maxcnt,mincnt);
    return 0;
}
