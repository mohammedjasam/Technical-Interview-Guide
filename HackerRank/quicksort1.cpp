/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void partition(vector <int>  ar) {
    vector<int> _small_ar, _large_ar;
    int val = ar[0];
    for(int i = 1; i < ar.size(); i ++){
        if(ar[i] > val)
            _large_ar.push_back(ar[i]);
        else
            _small_ar.push_back(ar[i]);
    }
    for(int i = 0; i < _small_ar.size(); i ++)
        cout<<_small_ar[i]<<" ";
    cout<<val<<" ";
    for(int i = 0; i < _large_ar.size(); i ++)
        cout<<_large_ar[i]<<" ";
    cout<<endl;
}
/* Tail starts here */
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

partition(_ar);
   
   return 0;
}
