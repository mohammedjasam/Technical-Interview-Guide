/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
int stk[N], maxstk[N], top, maxtop;
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    top = maxtop = 0;
    while(n -- ){
        int x, v;
        scanf("%d",&x);
        switch(x){
            case 1:scanf("%d",&v);
                stk[top ++] = v;
                if(!maxtop || v >= maxstk[maxtop - 1])
                    maxstk[maxtop ++] = v;
                break;
            case 2:
                v = stk[top - 1];
                -- top;
                if(v == maxstk[maxtop - 1])
                    -- maxtop;
                break;
            case 3:
                printf("%d\n",maxstk[maxtop - 1]);
                break;
        }
    }
    return 0;
}
