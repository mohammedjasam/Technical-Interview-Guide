/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int INT_MAX = 1<<30;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    vector<int> _rec;
    cin>>n;
    for(int i = 0; i < n; i ++) {
        int tmp;
        cin>>tmp;
        _rec.push_back(tmp);
    }
    sort(_rec.begin(),_rec.end());
    int _min_dif = INT_MAX;
    for(int i = 1; i < _rec.size(); i ++) {
        int _dif = _rec[i] - _rec[i - 1];
        _min_dif = min(_min_dif,_dif);
    }
    for(int i = 1; i < _rec.size(); i ++) {
        if(_min_dif == _rec[i] - _rec[i - 1])
            cout<<_rec[i - 1]<<" "<<_rec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
