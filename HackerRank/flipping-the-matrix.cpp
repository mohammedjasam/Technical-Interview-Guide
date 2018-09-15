/*
*
* Tag: Greedy
* Time: O(n^2)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 400;
int mtx[N][N], n;
int sumlw, sumhg, ans;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    scanf("%d",&q);
    while(q -- ){
        scanf("%d",&n);
        for(int i = 0; i < 2*n; ++ i){
            for(int j = 0; j < 2*n; ++ j){
                scanf("%d",&mtx[i][j]);
            }
        }
        ans = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                ans += max(max(mtx[i][j], mtx[2*n - 1 - i][j]), max(mtx[i][2*n - 1 - j], mtx[2*n - 1 - i][2*n - 1 - j]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

