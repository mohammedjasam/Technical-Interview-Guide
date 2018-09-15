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
const int N = 100100;
int s[N];
int n, m, v, id;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    scanf("%d%d",&n,&m);
    m %= n;
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        id = (i - m + n)%n;
        s[id] = v;
    }
    for(int i = 0; i < n; ++ i)
        printf("%d ",s[i]);
    return 0;
}
