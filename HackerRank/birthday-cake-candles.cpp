/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 300010;
int n, cnt, max_h, v;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    max_h = cnt = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        if(v > max_h){
            max_h = v;
            cnt = 1;
        }else if(v == max_h)
            ++ cnt;
    }
    printf("%d\n",cnt);
    return 0;
}
