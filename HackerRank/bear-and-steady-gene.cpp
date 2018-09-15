/*
*
* Tag: Brute Force (Two Pointers) 
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000010;
char s[N];
int recd[N][5];
int n;
int invn, invarr[5], inval[5];

int getid(char v){
    switch(v){
        case 'A':return 0;
        case 'C':return 1;
        case 'G':return 2;
        case 'T':return 3;
    }
    return -1;
}

bool check(int l, int r){
    int sum[4];
    for(int i = 0; i < 4; ++ i){
        sum[i] = recd[r][i];
        if(l >= 0)
            sum[i] -= recd[l][i];
    }
    for(int i = 0; i < invn; ++ i){
        if(sum[invarr[i]] < inval[invarr[i]])
            return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    scanf("%s",s);
    memset(recd, 0, sizeof(recd));
    memset(inval, 0, sizeof(inval));
    for(int i = 0; i < n; ++ i){
        int sum[4] = {0,0,0,0};
        if(i){
            for(int j = 0; j < 4; ++ j){
                sum[j] = recd[i - 1][j];
            }
        }
        ++ sum[getid(s[i])];
        for(int j = 0; j < 4; ++ j){
            recd[i][j] = sum[j];
        }
    }
    invn = 0;
    for(int i = 0; i < 4; ++ i){
        if(recd[n - 1][i] > n/4){
            invarr[invn ++] = i;
            inval[i] = recd[n - 1][i] - n/4;
        }
    }
/*    printf("%d\n",invn);
    for(int i = 0; i < invn; ++ i){
        printf("%d --> %d\n",invarr[i], inval[invarr[i]]);
    } */
    if(!invn){
        puts("0");
    }else{
        int l = -1, r = 0;
        int ans = INT_MAX;
        for(; r < n; ++ r){
            if(check(l, r)){
                while(l < r){
                    ++ l;
                    if(!check(l, r))
                        break;
                }
                if(l == -1)
                    ans = min(ans, r);
                else
                    ans = min(ans, r - l + 1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
