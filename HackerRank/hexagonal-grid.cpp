/*
*
* Tag: DFS (DP is best)
* Time: O(2^n)
* Space: O(n)
*/
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 15;
bool isblk[2][N],iscomplete;
char dom[N];
int n, tot;

void dfs(int depth){
    if(depth >= n){
        if(!tot){
            iscomplete = true;
        }
        return ;
    }
    if(isblk[0][depth] && isblk[1][depth]){
        dfs(depth + 1);
    }else{
       if(!isblk[0][depth] && !isblk[1][depth]){
           tot -= 2;
           isblk[0][depth] = isblk[1][depth] = 2;
           dfs(depth + 1);
           if(iscomplete)
               return ;
           tot += 2;
           isblk[0][depth] = isblk[1][depth] = 0;
       }else if(isblk[0][depth]){
           if(depth + 1 < n && !isblk[0][depth + 1]){
               tot -= 2;
               isblk[1][depth] = isblk[0][depth + 1] = 3;
               dfs(depth + 1);
               if(iscomplete)
                    return ;
               tot += 2;
               isblk[1][depth] = isblk[0][depth + 1] = 0;
           }
           if(depth + 1 < n && isblk[0][depth + 1] && !isblk[1][depth + 1]){
               tot -= 2;
               isblk[1][depth] = isblk[1][depth + 1] = 4;
               dfs(depth + 1);
               if(iscomplete)
                    return ;
               tot += 2;
               isblk[1][depth] = isblk[1][depth + 1] = 0;
           }
       }else{
           if(depth + 1 < n && !isblk[0][depth + 1]){
               tot -= 2;
               isblk[0][depth] = isblk[0][depth + 1] = 4;
               dfs(depth + 1);
               if(iscomplete)
                    return ;
               tot += 2;
               isblk[0][depth] = isblk[0][depth + 1] = 0;
           }
       }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        tot = 2*n;
        for(int i = 0; i < 2; ++ i){
            scanf("%s",dom);
            for(int j = 0; j < n; ++ j){
                isblk[i][j] = dom[j] - '0';
                if(isblk[i][j])
                    -- tot;
            }
        }
        iscomplete = false;
        dfs(0);
        if(iscomplete)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
