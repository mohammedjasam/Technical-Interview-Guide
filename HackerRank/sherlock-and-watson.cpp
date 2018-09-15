/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    int n, k, q;
    scanf("%d%d%d",&n,&k,&q);
    vector<int> v1, v2;
    v1.resize(n);
    v2.resize(n);
    for(int i = 0; i < n; i ++)
        scanf("%d",&v1[i]);
    for(int i = 0; i < n; i ++){
        int pos = (i + k)%n;
        v2[pos] = v1[i];
    }
    for(int i = 0; i < q; i ++){
        int a;
        scanf("%d",&a);
        printf("%d\n",v2[a]);
    }
    return 0;
}
