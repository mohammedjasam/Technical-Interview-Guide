/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&m);
    int tr = n/2, onr = n%2, tc = m/2, onc = m%2;
    printf("%d\n",tr*tc+tr*onc+onr*tc+onr*onc);
    return 0;
}
