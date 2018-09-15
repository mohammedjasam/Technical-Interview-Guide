/*
*
* Tag: Data Structure
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
int stk[2][N];
int top[2], q, x, op;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&q);
    top[0] = top[1] = 0;
    while(q --){
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%d",&x);
                stk[1][top[1] ++] = x; 
                break;
            case 2:
                if(top[0] == 0){
                    while(top[1]){
                        stk[0][top[0] ++] = stk[1][-- top[1]];
                    }
                }
                -- top[0];
                break;
            case 3:
                if(top[0] == 0){
                    while(top[1]){
                        stk[0][top[0] ++] = stk[1][-- top[1]];
                    }
                }
                printf("%d\n",stk[0][top[0] - 1]);
                break;
        }
    }
    return 0;
}
