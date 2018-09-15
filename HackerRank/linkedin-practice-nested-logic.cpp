/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int calnd[2][3];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(int i = 0; i < 2; ++ i){
        for(int j = 0; j < 3; ++ j)
            scanf("%d",&calnd[i][j]);
    }
    int ans = 0;
    if(calnd[0][2] < calnd[1][2])
        ans = 0;
    else if(calnd[0][2] > calnd[1][2])
        ans = 10000;
    else if(calnd[0][1] > calnd[1][1])
        ans = 500*(calnd[0][1] - calnd[1][1]);
    else if(calnd[0][0] > calnd[1][0])
        ans = 15*(calnd[0][0] - calnd[1][0]);
    printf("%d\n",ans);
    return 0;
}
