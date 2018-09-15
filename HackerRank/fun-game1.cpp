/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1100;
struct points{
    int a, b;
    bool operator < (const points &p) const{
        return a + b > p.a + p.b;
    }
}vec[N];
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        for(int i = 0; i < n; ++ i){
            scanf("%d",&vec[i].a);
        }
        for(int i = 0; i < n; ++ i){
            scanf("%d",&vec[i].b);
        }
        sort(vec, vec + n);
        int tot_a = 0, tot_b = 0;
        for(int i = 0; i < n; ++ i){
            if(i&1)
                tot_b += vec[i].b;
            else
                tot_a += vec[i].a;
        }
        if(tot_a == tot_b)
            puts("Tie");
        else if(tot_a > tot_b)
            puts("First");
        else
            puts("Second");
    }
    return 0;
}
