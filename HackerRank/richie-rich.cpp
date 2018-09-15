/*
*
* Tag:  Brute Force
* Time: O(n)
* Space: O(1)
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 100100;
char s[N];
int n, k;

int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int i = 0, j = strlen(s) - 1;
    int dif_pair = 0;
    while(i < j){
        if(s[i] != s[j])
            ++ dif_pair;
        ++ i;
        -- j;
    }
    if(dif_pair > k){
        puts("-1");
    }else{
        i = 0, j = strlen(s) - 1;
        int cnt = 0;
        while(i <= j){
            if(s[i] != s[j]){
                -- dif_pair;
                if(max(s[i], s[j]) != '9'){
                    if(dif_pair + cnt + 2 <= k){
                        s[i] = s[j] = '9';
                        cnt += 2;
                    }else{
                        s[i] = s[j] = max(s[i], s[j]);
                        ++ cnt;
                    }
                }else{
                    ++ cnt;
                    s[i] = s[j] = '9';
                }
            }else{
                if(max(s[i], s[j]) != '9'){
                    if(dif_pair + cnt + 2 <= k){
                        cnt += 2;
                        s[i] = s[j] = '9';
                    }else if(i == j && cnt + 1 <= k){
                        ++ cnt;
                        s[i] = s[j] = '9';
                    }
                }
            }
            ++ i;
            -- j;
        }
        puts(s);
    }
    return 0;
}
