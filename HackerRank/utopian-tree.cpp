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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T --){
        int n;
        cin>>n;
        long long _ans = 1;
        for(int i = 0; i < n; i ++) {
            if(i%2 == 0)
                _ans = _ans*2;
            else
                _ans += 1;
        }
        cout<<_ans<<endl;
    }
    return 0;
}
