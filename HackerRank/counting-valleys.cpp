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
const int N = 1001000;
int n;
char stp[N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%s",&n,stp);
    int cnt = 0, lv = 0;
    for(int i = 0; i < n; ++ i){
        if(stp[i] == 'U')
            ++ lv;
        else{
            if(lv == 0)
                ++ cnt;
            -- lv;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
