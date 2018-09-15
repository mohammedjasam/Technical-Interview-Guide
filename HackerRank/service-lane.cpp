/*
*
* Tag: Greedy
* Time: O(tn) 
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,t;
    vector<int> lane;
    cin>>n>>t;
    for(int i = 0; i < n; i ++) {
        int tmp;
        cin>>tmp;
        lane.push_back(tmp);
    }
    int l,r;
    for(int i = 0; i < t; i ++) {
        int _ans = 5;
        cin>>l>>r;
        for(int j = l; j <= r; j ++)
            _ans = min(_ans,lane[j]);
        cout<<_ans<<endl;
    }
    return 0;
}
