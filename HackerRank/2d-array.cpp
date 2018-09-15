/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[10][10];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(int i = 0; i < 6; ++ i){
        for(int j = 0; j < 6; ++ j)
            scanf("%d",&a[i][j]);
    }
    int ans = INT_MIN;
    for(int i = 0; i < 4; ++ i){
        for(int j = 0; j < 4; ++ j){
            int sum = 0;
            sum = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1] + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
            ans = max(ans, sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}
