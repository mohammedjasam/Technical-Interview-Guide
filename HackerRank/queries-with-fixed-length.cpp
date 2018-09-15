/*
*
* Tag: Data Structure (Deque)
* Time: O(n)
* Space: O(n)
*/
#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 111000;
int n, q, d;
int a[N];
deque<int> dq;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&a[i]);
    while(q --){
        scanf("%d",&d);
        dq.clear();
        int ans = INT_MAX;
        for(int i = 0; i < n; ++ i){
            while(dq.size() && a[dq.back()] < a[i])
                dq.pop_back();
            dq.push_back(i);
            while(dq.size() && a[dq.front()] <= i - d)
                dq.pop_front();
            if(i >= d - 1 ){
                ans = min(ans, a[dq.front()]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
