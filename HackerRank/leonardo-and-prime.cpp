/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 25;
long long primearr[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int q;
long long n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&q);
    while(q --){
        scanf("%lld",&n);
        int cnt = 0, idx = 0;
        long long cur = 1, pre = 0;
        while(cur < n && cur > pre){
            pre = cur;
            cur *= primearr[idx ++];
            if(cur > n || cur <= pre)
                break;
            ++ cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
