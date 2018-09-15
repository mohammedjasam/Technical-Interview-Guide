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
int n, k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&n,&k);
        int inpt, cnt = 0;
        for(int i = 0; i < n; ++ i){
            scanf("%d",&inpt);
            if(inpt <= 0)
                ++ cnt;
        }
        if(cnt < k)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
