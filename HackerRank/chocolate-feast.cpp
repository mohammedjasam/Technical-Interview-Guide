/*
*
* Tag: Implementation
* Time: 
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    int n,c,m;
    cin>>T;
    while(T--){
        cin>>n>>c>>m;
        int ans = 0,_newchol = 0;
        _newchol = n/c;
        ans += _newchol;
        while(_newchol >= m){
            int sum = 0;
            sum += _newchol/m;
            _newchol = _newchol/m + _newchol%m;
            ans += sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}
