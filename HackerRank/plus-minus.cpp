/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int pos_cnt, neg_cnt, zero_cnt;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    int v;
    pos_cnt = neg_cnt = zero_cnt = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        if(!v){
            ++ zero_cnt;
        }else if(v > 0){
            ++ pos_cnt;
        }else
            ++ neg_cnt;
    }
    printf("%.4lf\n%.4lf\n%.4lf\n",(double)pos_cnt/(double)n,(double)neg_cnt/(double)n, (double)zero_cnt/(double)n);
    return 0;
}
