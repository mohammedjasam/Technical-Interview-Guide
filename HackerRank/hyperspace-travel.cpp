/*
*
* Tag: Geometry
* Time: O(mnlgn)
* Space: O(nm)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 11000;
const int M = 200;
int n, m;
int x[M][N], ans[M];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            scanf("%d",&x[j][i]);
        }
    }
    for(int i = 0; i < m; ++ i){
        sort(x[i], x[i] + n);
        if(n & 1){
            ans[i] = x[i][n/2];
        }else{
            ans[i] = x[i][n/2 - 1];
        }
    }
    for(int i = 0; i < m; ++ i)
        printf("%d ",ans[i]);
    puts("");
    return 0;
}

