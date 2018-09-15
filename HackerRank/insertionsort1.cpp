/*
*
* Tag: Sort
* Time: O(n^2)
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

void output(vector<int> ar){
    for(int i = 0; i < ar.size(); i ++)
        cout<<ar[i]<<" ";
    cout<<endl;
}

void insertionSort(vector <int>  ar) {
    for(int i = 1; i < ar.size(); i ++){
        int val = ar[i];
        int j = i - 1;
        bool _is_sort = false;
        while(j >= 0 && val < ar[j]) {
            ar[j + 1] = ar[j];
            -- j;
            output(ar);
            _is_sort = true;
        }
        ar[j + 1] = val;
        if(_is_sort) output(ar);
    }
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

insertionSort(_ar);
   
   return 0;
}
