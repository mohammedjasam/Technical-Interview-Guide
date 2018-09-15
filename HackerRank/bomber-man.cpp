/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n^2)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 300;
int r, c, n;
char mp[N][N];
bool pre[N][N], cur[N][N];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d%d",&r,&c,&n);
    for(int i = 0; i < r; ++ i)
        scanf("%s",mp[i]);
    memset(pre, 0, sizeof(pre));
    memset(cur, 0, sizeof(cur));
    for(int i = 0; i < r; ++ i){
        for(int j = 0; j < c; ++ j){
            if(mp[i][j] == 'O')
                pre[i][j] = cur[i][j] = 1;
        }
    }
    n --;
    if(n){
        n %= 4;
        for(int i = 0; i < r; ++ i){
            for(int j = 0; j < c; ++ j)
                cur[i][j] = 1;
        }
        if(n%2 == 0){
            for(int i = 0; i < r; ++ i){
                for(int j = 0; j < c; ++ j){
                    if(pre[i][j] == 1){
                        cur[i][j] = 0;
                        for(int k = 0; k < 4; ++ k){
                            int nx = i + dir[k][0], ny = j + dir[k][1];
                            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                                cur[nx][ny] = 0;
                            }
                        }
                    }
                }
            }
        }
        if(n == 0){
            for(int i = 0; i < r; ++ i){
                for(int j = 0; j < c; ++ j)
                    pre[i][j] = cur[i][j];
            }
            for(int i = 0; i < r; ++ i){
                for(int j = 0; j < c; ++ j){
                    cur[i][j] = 1;
                }
            }
            for(int i = 0; i < r; ++ i){
                for(int j = 0; j < c; ++ j){
                    if(pre[i][j] == 1){
                        cur[i][j] = 0;
                        for(int k = 0; k < 4; ++ k){
                            int nx = i + dir[k][0], ny = j + dir[k][1];
                            if(nx >= 0 && nx < r && ny >= 0 && ny < c){
                                cur[nx][ny] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < r; ++ i){
        for(int j = 0; j < c; ++ j){
            if(cur[i][j])
                mp[i][j] = 'O';
            else
                mp[i][j] = '.';
        }
    }
    for(int i = 0; i < r; ++ i)
        puts(mp[i]);
    return 0;
}
