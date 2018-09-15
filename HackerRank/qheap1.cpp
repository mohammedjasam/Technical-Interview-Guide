/*
*
* Tag: Data Structure (Heap)
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int q;
priority_queue<int, vector<int>, greater<int> > pq, pqdel;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&q);
    while(q --){
        int x, v;
        scanf("%d",&x);
        switch(x){
            case 1:scanf("%d",&v);
                pq.push(v);
                break;
            case 2:scanf("%d",&v);
                pqdel.push(v);
                break;
            case 3:
                while(!pq.empty() && !pqdel.empty() && pq.top() == pqdel.top()){
                    pq.pop();
                    pqdel.pop();
                }
                printf("%d\n",pq.top());
                break;
        }
    }
    return 0;
}
