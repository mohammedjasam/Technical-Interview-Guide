/*
*
* Tag: Data Structure (Stack)
* Time: O(qn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1300;
const int M = 110000;
int ans[M], stk[M], tmpstk[M],prim[N];
int atop, top, ttop, n,q, num;

void init(){
    num = 0;
    for(int i = 2; i < M; ++ i){
        bool isfind = false;
        for(int j = 2; j <= sqrt(i); ++ j){
            if(i%j==0){
                isfind = true;
                break;
            }
        }
        if(!isfind){
            prim[num ++] = i;
        }
        if(num >= 1200)
            return ;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&q);
    init();
    atop = top = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&stk[top ++]);
    }
    for(int i = 0; i < q; ++ i){
        ttop = 0;
        while(top){
            int v = stk[top - 1];
            -- top;
            if(v%prim[i] == 0){
                ans[atop ++] = v;
            }else{
                tmpstk[ttop ++] = v;
            }
        }
        while(atop){
            printf("%d\n",ans[atop - 1]);
            -- atop;
        }
        for(int j = 0; j < ttop; ++ j){
            stk[j] = tmpstk[j];
        }
        top = ttop;
        if(!top)
            break;
    }
    while(top){
        printf("%d\n",stk[top - 1]);
        -- top;
    }
    return 0;
}
