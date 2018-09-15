/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1100;
char a[N], b[N];
int cnt[N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    int i = 0, j = 0;
    bool isfind = true;
    while(T --){
        scanf("%s%s",a,b);
        memset(cnt, 0, sizeof(cnt));
        isfind = true;
        for(i = 0; b[i]; ++ i)
            ++ cnt[b[i] - 'A'];
        for(i = 0; a[i]; ++ i){
            if(a[i] >= 'A' && a[i] <= 'Z')
                -- cnt[a[i] - 'A'];
            if(cnt[a[i] - 'A'] < 0){
                isfind = false;
                break;
            }
        }
        if(!isfind){
            puts("NO");
            continue;
        }
        i = j = 0;
        while(a[i] && b[j]){
            if(a[i] >= 'a' && a[i] <= 'z')
                a[i] ='A' + (a[i] - 'a');
            if(a[i] == b[j])
                ++ j;
            ++ i;
        }
        if(!b[j]){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}
