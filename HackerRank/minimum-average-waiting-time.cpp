/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Customer{
    int starttime, lasttime;
    bool operator < (Customer a) const{
        if(starttime == a.starttime)
            return lasttime < a.lasttime;
        return starttime < a.starttime;
    }
};
vector<Customer> waitlist;
long long tottime;
int n;
struct cmp{
    bool operator() (const int &a, const int &b){
        return waitlist[a].lasttime > waitlist[b].lasttime;
    }
};
priority_queue<int,vector<int>,cmp > pq;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    waitlist.resize(n);
    for(int i = 0; i < n; ++ i){
        scanf("%d%d",&waitlist[i].starttime,&waitlist[i].lasttime);
    }
    sort(waitlist.begin(), waitlist.end());
    tottime = 0;
    long long endtime = waitlist[0].starttime;
    int idx = 1;
    pq.push(0);
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        tottime += waitlist[u].lasttime + (endtime - waitlist[u].starttime);
        endtime += waitlist[u].lasttime;
        while(idx < n && waitlist[idx].starttime <= endtime){
            pq.push(idx);
            ++ idx;
        }
    }
    printf("%lld\n",tottime/n);
    return 0;
}
