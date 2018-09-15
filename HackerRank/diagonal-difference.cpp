/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200;
int mtx[N][N];
int sum1, sum2, n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < n; ++ j)
            scanf("%d",&mtx[i][j]);
    sum1 = sum2 = 0;
    for(int i = 0; i < n; ++ i)
        sum1 += mtx[i][i];
    for(int i = 0, j = n - 1; i < n; ++ i, -- j)
        sum2 += mtx[i][j];
    printf("%d\n",abs(sum1 - sum2));
    return 0;
}
