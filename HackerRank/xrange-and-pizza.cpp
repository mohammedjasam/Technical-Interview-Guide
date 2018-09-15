/*
*
* Tag: Geometry
* Time: O(m)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, t, k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&m);
    int x = 2*n, pos = 0;
    bool isflipped = false;
    for(int i = 0; i < m; ++ i){
        scanf("%d%d",&t,&k);
        if(t == 1){
            pos = (pos + k*2)%x;
        }else{
            pos = (pos + ((k + x - pos)%x)*2 )%x;
            isflipped = !isflipped;
        }
    }
    if(!isflipped){
        printf("1 %d\n",(x - pos)/2);
    }else{
        printf("2 %d\n",pos/2);
    }
    return 0;
}
