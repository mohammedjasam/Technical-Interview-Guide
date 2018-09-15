/*
*
* Tag: Data Structure (Trie) && DP
* Time: O(nm) where m is the average length of given string
* Space: O(n^26)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int NN = 30;
const int N = 3000100;
const int M = 27;
int tree[N][M], end_ch[N], dp[N], pre[N];
int sz, n, ans;
char op[NN], str[NN];

void init(){
    sz = 1;
    memset(tree[0], 0, sizeof(tree[0]));
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    pre[0] = -1;
}

void insert(){
    int u = 0;
    for(int i = 0; str[i]; ++ i){
        int idx = str[i] - 'a';
        if(!tree[u][idx]){
            memset(tree[sz], 0, sizeof(tree[sz]));
            pre[sz] = u;
            tree[u][idx] = sz ++;
        }
        u = tree[u][idx];
    }
    end_ch[u] = -1;
    while(u){
        ++ dp[u];
        u = pre[u];
    }
}

void find(){
    int u = 0, len = strlen(str);
    for(int i = 0; i < len; ++ i){
        int idx = str[i] - 'a';
        if(!tree[u][idx]){
            return ;
        }
        u = tree[u][idx];
    }
    ans = dp[u];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    init();
    for(int i = 0; i < n; ++ i){
        scanf("%s%s",op,str);
        if(strcmp(op,"add") == 0){
            insert();
        }else{
            ans = 0;
            find();
            printf("%d\n",ans);
        }
    }
    return 0;
}
