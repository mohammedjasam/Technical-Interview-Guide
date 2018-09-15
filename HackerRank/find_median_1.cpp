/*
*
* Tag: Heap (Data Structure)
* Time: O(nlogn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
priority_queue<int> lg_q;
priority_queue<int, vector<int>, greater<int> > sm_q;
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    int cnt = 0;
    while(n -- ){
        double ans = 0;
        int lval, rval;
        int inpt;
        scanf("%d",&inpt);
        ++ cnt;
        if(cnt == 1){
            ans = inpt;
            lg_q.push(inpt);
        }else{
            if(inpt <= lg_q.top()){
                lg_q.push(inpt);
                if(lg_q.size() > sm_q.size() + 1){
                    inpt = lg_q.top();
                    lg_q.pop();
                    sm_q.push(inpt);
                }
            }else{
                sm_q.push(inpt);
                if(lg_q.size() < sm_q.size()){
                    inpt = sm_q.top();
                    sm_q.pop();
                    lg_q.push(inpt);
                }
            }
            if(lg_q.size() == sm_q.size()){
                lval = lg_q.top();
                rval = sm_q.top();
                ans = ((double)lval + (double)rval)/2.0;
            }else{
                ans = lg_q.top();
            }
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}
