/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1000100;

int main(){
    int T;
    cin>>T;
    while(T--){
        vector<bool> ans(M, false);
        int n, a, b;
        cin>>n>>a>>b;
        for(int i = 0; i < n; i ++){
            int val = i*a + (n - i - 1)*b;
            if(!ans[val]){
                ans[val] = true;
            }
        }
        for(int i = 0; i < M; i ++){
            if(ans[i])
                cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
