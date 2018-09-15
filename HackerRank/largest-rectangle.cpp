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
#include <stack>
#include <algorithm>
using namespace std;
const int N = 100010;
int n;
int h[N];
stack<int> stk;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&h[i]);
    }
    h[n] = 0;
    int ans = 0;
    for(int i = 0; i <= n; ){
        if(stk.empty() || h[i] > h[stk.top()]){
            stk.push(i ++);
        }else{
            int id = stk.top();
            stk.pop();
            ans = max(ans, h[id]*(stk.empty()?i:i-stk.top() - 1));
        }
    }
    printf("%d\n",ans);
    return 0;
}
