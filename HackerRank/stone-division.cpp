/*
*
* Tag: Game Theory
* Time: O(n^(1/3)*m*lgn)
* Space: O(n^(1/3))
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 20;
unordered_map<long long, bool> sg;
int m;
long long n, s[N];

bool Grundy(long long n){
    if(sg.count(n))
        return sg[n];
    bool ans = 0;
    for(int i = 0; i < m; ++ i){
        if(n%s[i])
            continue;
        if(s[i]&1)
            ans |= (Grundy(n/s[i]) == 0);
        else
            ans |= 1;
        if(ans)
            break;
    }
    sg[n] = ans;
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    scanf("%lld%d",&n,&m);
    for(int i = 0; i < m; ++ i)
        scanf("%lld",&s[i]);
    if(Grundy(n))
        puts("First");
    else
        puts("Second");
    return 0;
}
