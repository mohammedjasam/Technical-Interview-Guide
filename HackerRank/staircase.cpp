/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    int num_space = n - 1;
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j < num_space; ++ j)
            printf(" ");
        for(int j = 0; j < i; ++ j)
            printf("#");
        puts("");
        -- num_space;
    }
    return 0;
}
