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
int n, sum;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sum = 0;
    scanf("%d",&n);
    while(n --){
        int a;
        scanf("%d",&a);
        sum += a;
    }
    printf("%d\n",sum);
    return 0;
}
