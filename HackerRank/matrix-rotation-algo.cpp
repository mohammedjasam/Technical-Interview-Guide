/*
*
* Tag: Implementation
* Time: O(rc)
* Space: O(rc)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 500;
const int N = 500;
int org[M][N], ans[M][N];
int n, m, r;

void change(int &r, int &c, int st_r, int st_c, int n, int m, int &cas){
    if(cas == 0){
        -- r;
        if(r == st_r)
            cas = 3;
    }else if(cas == 1){
        -- c;
        if(c == st_c)
           cas = 0;
    }else if(cas == 2){
        ++ r;
        if(r == st_r + n - 1)
            cas = 1;
    }else{
        ++ c;
        if(c == st_c + m - 1)
            cas = 2;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d%d",&n,&m,&r);
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            scanf("%d",&org[i][j]);
        }
    }

    int st_r = 0, st_c = 0;
    int R = n, C = m;
    while(n > 0 && m > 0){
        int stp = (r%(2*(m + n) - 4));
        if(stp > 0){
            int i = st_r, j = st_c;
            int t_r, t_c, cas;
            if(stp < n){
                t_r = i + stp;
                t_c = j;
                cas = 0;
            }else if(stp < n + m - 1){
                t_r = i + n - 1;
                t_c = j + stp - n + 1;
                cas = 1;
            }else if(stp < 2*n + m - 2){
                t_r = i + (n - 1 - (stp - (n + m - 2)));
                t_c = j + m - 1;
                cas = 2;
            }else{
                t_r = i;
                t_c = j + (m - 1 - (stp - (2*n + m - 3)));
                cas = 3;
            }
            for(; j < st_c + m; ++ j){
                ans[t_r][t_c] = org[i][j];
                change(t_r, t_c, st_r, st_c, n, m, cas);
            }
            -- j;
            ++ i;
            for(; i < st_r + n; ++ i){
                ans[t_r][t_c] = org[i][j];
                change(t_r, t_c, st_r, st_c, n, m, cas);
            }
            -- i;
            -- j;
            for(; j >= st_c; -- j){
                ans[t_r][t_c] = org[i][j];
                change(t_r, t_c, st_r, st_c, n, m, cas);
            }
            ++ j;
            -- i;
            for(; i >= st_r; -- i){
                ans[t_r][t_c] = org[i][j];
                change(t_r, t_c, st_r, st_c, n, m, cas);
            }
            ++ i;
        }else{
            for(int i = st_r; i < st_r + n; ++ i){
                for(int j = st_c; j < st_c + m; ++ j){
                    ans[i][j] = org[i][j];
                }
            }
        }
        n -= 2;
        m -= 2;
        ++ st_r;
        ++ st_c;
    }
    for(int i = 0; i < R; ++ i){
        for(int j = 0; j < C; ++ j){
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
