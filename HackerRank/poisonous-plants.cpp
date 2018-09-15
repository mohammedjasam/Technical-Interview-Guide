/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int plt[N];
int stk1[N], stk2[N];
int tp1 = 0, tp2 = 0;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&plt[i]);
    int ans = 0;
    stk1[tp1 ++] = plt[0];
    stk2[tp2 ++] = 0;
    for(int i = 1; i < n; ){
        if(plt[i] <= stk1[tp1 - 1]){
            stk1[tp1 ++] = plt[i];
            stk2[tp2 ++] = 0;
            ++ i;
            continue;
        }
        int id = i;
        while(id < n){
            while(id < n && plt[id] > stk1[tp1 - 1]){
                stk1[tp1 ++] = plt[id];
                stk2[tp2 ++] = 1;
                ++ id;
            }
            if(id >= n){
                ans = max(ans, 1);
                break;
            }
            int val = 0;
            while(tp1 && plt[id] <= stk1[tp1 - 1]){
                val = max(val, stk2[tp2 - 1] + 1);
                -- tp2;
                -- tp1;
            }
            if(!tp1 || stk1[tp1 - 1] >= plt[id]){
                stk1[tp1 ++] = plt[id];
                stk2[tp2 ++] = 0;
                ++ id;
                ans = max(1, ans);
                break;
            }
            ans = max(val, ans);
            stk1[tp1 ++] = plt[id];
            stk2[tp2 ++] = val;
            ++ id;
        }
        i = id;
    }
    printf("%d\n",ans);
    return 0;
}
