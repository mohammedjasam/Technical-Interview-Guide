/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dict[8][3][3] = { {{8, 1, 6},{3, 5, 7},{4, 9, 2}}, 
                      {{6, 1, 8},{7, 5, 3},{2, 9, 4}},
                      {{2, 9, 4},{7, 5, 3},{6, 1, 8}},
                      {{4, 9, 2},{3, 5, 7},{8, 1, 6}},
                      {{8, 3, 4},{1, 5, 9},{6, 7, 2}},
                      {{4, 3, 8},{9, 5, 1},{2, 7, 6}},
                      {{6, 7, 2},{1, 5, 9},{8, 3, 4}},
                      {{2, 7, 6},{9, 5, 1},{4, 3, 8}}
                    };
int mtx[3][3], ans;

void check(){
    int cnt = 0;
    for(int i = 0; i < 8; ++ i){
        cnt = 0;
        for(int j = 0; j < 3; ++ j){
            for(int k = 0; k < 3; ++ k){
                cnt += abs(dict[i][j][k] - mtx[j][k]);
            }
        }
        ans = min(ans, cnt);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(int i = 0; i < 3; ++ i){
        for(int j = 0; j < 3; ++ j)
            scanf("%d",&mtx[i][j]);
    }
    ans = INT_MAX;
    check();
    printf("%d\n",ans);
    return 0;
}
