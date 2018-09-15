/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n^2)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<map>
#include<algorithm>
using namespace std;
const int MOD = 1000000007;
    
int main(){
    int n;
    while(cin>>n){
        vector<string> mp;
        vector<string> ans;
        mp.resize(n);
        ans.resize(n);
        for(int i = 0; i < n; i ++){
            cin>>mp[i];
            ans[i] = mp[i];
        }
        for(int i = 1; i < n - 1; i ++){
            for(int j = 1; j < n - 1; j ++){
                int val = mp[i][j] - '0';
                int up = mp[i - 1][j] - '0';
                int down = mp[i + 1][j] - '0';
                int left = mp[i][j - 1] - '0';
                int right = mp[i][j + 1] - '0';
                if(val > up && val > down && val > left && val > right){
                    ans[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < n; i ++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
