/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1100;
int n;
int arr[N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n ; ++ i)
        scanf("%d",&arr[i]);
    for(int i = n - 1; i >= 0; -- i)
        printf("%d ",arr[i]);
    puts("");
    return 0;
}
