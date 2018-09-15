/*
*
* Tag: Sort
* Time: O(nlgn)
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
void quickSort(vector <int>  &ar, int ar_size) {
    if(ar_size <= 1) return ;
    vector<int> _small_ar, _large_ar;
    int val = ar[0];
    for(int i = 1; i < ar_size; i ++){
        if(val < ar[i])
            _large_ar.push_back(ar[i]);
        else
            _small_ar.push_back(ar[i]);
    }
    quickSort(_small_ar, _small_ar.size());
    quickSort(_large_ar, _large_ar.size());
    int ind = 0;
    for(int i = 0; i < _small_ar.size(); i ++)
        ar[ind ++] = _small_ar[i];
    ar[ind ++] = val;
    for(int i = 0; i < _large_ar.size(); i ++)
        ar[ind ++] = _large_ar[i];
    for(int i = 0; i < ar_size; i ++)
        cout<<ar[i]<<" ";
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

quickSort(_ar, _ar_size);
   
   return 0;
}
