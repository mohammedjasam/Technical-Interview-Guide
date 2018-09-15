/*
*
* Tag: Queue (Data Structure)
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct station{
    int pet, dist;
    int idx;
};
int n;
queue<station> q;
vector<station> v_stat;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    v_stat.resize(n);
    for(int i = 0; i < n; ++ i){
        scanf("%d%d",&v_stat[i].pet,&v_stat[i].dist);
        v_stat[i].idx = i;        
    }
    long long tot_pet = 0, tot_dist = 0;
    int idx = 0;
    while(q.size() < n){
        tot_pet += v_stat[idx].pet;
        tot_dist += v_stat[idx].dist;
        q.push(v_stat[idx]);
        if(tot_pet < tot_dist){
            while(!q.empty()){
                station tmp = q.front();
                q.pop();
                tot_pet -= tmp.pet;
                tot_dist -= tmp.dist;
                if(tot_pet >= tot_dist){
                    break;
                }
            }
        }
        idx = (idx + 1)%n;
    }
    printf("%d\n",q.front().idx);
    return 0;
}
