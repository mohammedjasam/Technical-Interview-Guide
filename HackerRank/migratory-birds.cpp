/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int n, v, dict[6];

int main(){
    scanf("%d",&n);
    memset(dict, 0, sizeof(dict));
    for(int i = 0; i < n; ++ i){
        scanf("%d",&v);
        ++ dict[v];
    }
    int ans_id = 0, ans_cnt = 0;
    for(int i = 1; i <= 5; ++ i){
        if(dict[i] > ans_cnt){
            ans_cnt = dict[i];
            ans_id = i;
        }
    }
    printf("%d\n",ans_id);
    return 0;
}
