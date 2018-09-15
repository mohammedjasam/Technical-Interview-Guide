/*
*
* Tag: Game
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&m,&n);
        if(n == 1 || m%2 == 0)
            puts("2");
        else
            puts("1");
    }
    return 0;
}
