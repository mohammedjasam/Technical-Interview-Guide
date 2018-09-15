/*
*
* Tag: Game
* Time: O(sqrt(n))
* Space: O(sqrt(n))
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int N = 110;
const int M = 100100;
int sg[M], n, v;

int grundy(int v);



int mergeSG(int x, int y){
    if(x&1)
        return grundy(y);
    return 0;
}

int grundy(int v){
    if(sg[v] != -1)
        return sg[v];
    set<int> st;
    for(int i = 1; i*i <= v && i < v; ++ i){
        if(v%i)
            continue;
        if(i > 1)
            st.insert(mergeSG(i, v/i));
        st.insert(mergeSG(v/i, i));
    }
    int res = 0;
    while(st.count(res)) res++;
    return sg[v] = res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    fill(sg, sg + M, -1);
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            scanf("%d",&v);
            ans^=grundy(v);
        }
        puts(ans?"1":"2");
    }
    return 0;
}
