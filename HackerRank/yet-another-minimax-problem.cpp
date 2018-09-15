/*
*
* Tag: Bit Manipulation
* Time: O(n^2*lg(c)) where c is max(ai)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int N = 5000;
const long long mask = (1L<<31);
pair<int,int> mxv[N];
bool hasval[N];
long long arr[N], higharr[N], highcnt, ans;
int n, idx, dep;
unordered_set<long long> vis;

void init(){
    for(int i = 0; i < N; ++ i){
        mxv[i] = make_pair(INT_MAX,INT_MIN);
        hasval[i] = false;
    }
}

int getHightBit(long long v){
    if(!v)
        return 0;
    long long chk = mask;
    int res = 31;
    while(chk){
        if(chk&v)
            return res;
        -- res;
        chk >>= 1;
    }
    return res;
}

void solve(){
    vis.clear();
    for(int i = 0; i < n; ++ i)
        vis.insert(arr[i]);
    if(vis.size() == 1){
        ans = 0;
        return ;
    }
    int maxidx = 0, minidx =  32;
    for(int i = 0; i < n; ++ i){
        idx = getHightBit(arr[i]);
        maxidx = max(maxidx, idx);
    }
    highcnt = 0;
    long long chk = (1L<<maxidx), v;
    for(int i = 0; i < n; ++ i){
        v = arr[i];
        if(chk&v){
            higharr[highcnt ++] = v;
        }
    }

    if(highcnt < n){
        for(unordered_set<long long>::iterator it = vis.begin(); it != vis.end(); ++ it){
            v = *it;
            if((chk&v) == 0){
                for(int j = 0; j < highcnt; ++ j){
                    ans = min(ans, v^higharr[j]);
                }
            }
        }
    }else{
        int i = 0;
        for(unordered_set<long long>::iterator it = vis.begin(); it != vis.end(); ++ it){
            arr[i++]=(*it)^chk;
        }
        solve();
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%lld",&arr[i]);
    ans = INT_MAX;
    dep = 0;
    solve();
    printf("%lld\n",ans);
    return 0;
}
