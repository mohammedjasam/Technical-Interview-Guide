/*
*
* Tag: Hash
* Time: O(klgk)
* Space: O(k)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
long long ans, n, m;
unordered_map<int,vector<pair<int,int>>> track;
unordered_map<int,vector<pair<int,int>>>::iterator it;
int k, r, c1, c2;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%lld%lld%d",&n,&m,&k);
    ans = n*m;
    track.clear();
    for(int i = 0; i < k; ++ i){
        scanf("%d%d%d",&r,&c1,&c2);
        track[r].push_back(make_pair(c1,c2));
    }
    int u = 0, i = 0;
    pair<int,int> cur, now;
    for(it = track.begin(); it != track.end(); ++  it){
        u = it->first;
        sort(track[u].begin(), track[u].end(), cmp);
        i = 0;
        cur = track[u][i];
        for(i = 1; i < track[u].size(); ++ i){
            now = track[u][i];
            if((cur.second >= now.first - 1 && cur.second <= now.second) || 
               (cur.second >= now.first && cur.second >= now.second)){
                cur.second = max(cur.second, now.second);
            }else{
                ans -= (cur.second - cur.first + 1);
                cur = now;
            }
            if(i == track[u].size() - 1)
                    ans -= (cur.second - cur.first + 1);
        }
        if(track[u].size() == 1){
            ans -= (cur.second - cur.first + 1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
