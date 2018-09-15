/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int N = 101000;
unordered_set<string> dict;
int n, top, len, dp[N];
string s, v, ans[N], stk[N];

void init(){
    top = len = 0;
    dict.clear();
    for(int i = 0; i < N; ++ i)
        dp[i] = -1;
}

void solve(){
    string t = "";
    for(int i = 0; i < s.size(); ++ i){
        t += s[i];
        if(dict.find(t) != dict.end())
            dp[i] = 0;
    }
    for(int i = 1; i < s.size(); ++ i){
        t = "";
        for(int j = i; j > 0; -- j){
            t = s[j] + t;
            if(dict.find(t) != dict.end() && dp[j - 1] != -1){
                dp[i] = j;
                break;
            }
        }
    }
}
  
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T --){
        cin>>n;
        init();
        for(int i = 0; i < n; ++ i){
            cin>>v;
            dict.insert(v);
        }
        cin>>s;
        solve();
        if(dp[s.size() - 1] != -1){
            int idx = s.size() - 1;
            while(idx != -1){
                stk[top ++] = s.substr(dp[idx], idx - dp[idx] + 1);
                idx = dp[idx] - 1;
            }
            for(int i = top - 1; i >= 0; -- i)
                cout<<stk[i]<<" ";
            cout<<endl;
        }else
            cout<<"WRONG PASSWORD"<<endl;
    }
    return 0;
}
