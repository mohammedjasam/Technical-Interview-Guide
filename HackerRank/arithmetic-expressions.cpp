/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 11000;
const int MOD = 101;
int n, arr[N];
unordered_map<int,pair<string,int>> path[N];

void init(){
    for(int i = 0; i < N; ++ i)
        path[i].clear();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    cin>>n;
    for(int i = 0; i < n; ++ i)
       cin>>arr[i];
    path[0][arr[0]%MOD] = make_pair(arr[0]%MOD, 0);
    unordered_map<int,pair<string,int>>::iterator it;
    int v = 0;
    for(int i = 0; i < n - 1; ++ i){
        for(it = path[i].begin(); it != path[i].end(); ++ it){
            v = (it->first + arr[i + 1])%MOD;
            path[i + 1][v] = make_pair("+", it->first);
            v = (it->first - arr[i + 1] + MOD)%MOD;
            path[i + 1][v] = make_pair("-", it->first);
            v = (it->first * arr[i + 1])%MOD;
            path[i + 1][v] = make_pair("*", it->first);
        }
    }
    string ans = "";
    v = 0;
    pair<string,int> cur;
    for(int i = n - 1; i > 0; -- i){
        cur = path[i][v];
        ans = cur.first + to_string(arr[i]) + ans;
        v = cur.second;
    }
    ans = to_string(arr[0]) + ans;
    cout<<ans<<endl;
    return 0;
}
