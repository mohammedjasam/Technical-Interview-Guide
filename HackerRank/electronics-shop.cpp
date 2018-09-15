/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2000;
int p, n, m, sum;
int arr[2][N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int ans = -1;
    scanf("%d%d%d",&p,&n,&m);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&arr[0][i]);
    for(int i = 0; i < m; ++ i)
        scanf("%d",&arr[1][i]);
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            sum = arr[0][i] + arr[1][j];
            if(sum <= p)
                ans = max(ans, sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}
