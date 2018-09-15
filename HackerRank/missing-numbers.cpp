/*
*
* Tag: Hash
* Time: O(n)
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
    int n,m;
    int tmp;
    vector<int> _rec_a(20003,0),_rec_b(20003,0);
    cin>>n;
    for(int i = 0; i < n; i ++){
        cin>>tmp;
        _rec_a[(tmp + 10000)] ++;
    }
    cin>>m;
    for(int j = 0; j < m; j ++){
        cin>>tmp;
        _rec_b[(tmp + 10000)] ++;
    }
    for(int i = 0; i <= 20000; i ++){
        if(_rec_a[i] < _rec_b[i])
            cout<<i - 10000<<" ";
    }
    cout<<endl;
    return 0;
}
