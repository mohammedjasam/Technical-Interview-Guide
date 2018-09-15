/*
*
* Tag: Hash
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
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int pairs(vector < int > a,int k) {
   int ans = 0;
   set<int> rec;
   rec.clear();
   sort(a.begin(),a.end());
   for(int i = 0; i < a.size(); i ++)
      rec.insert(a[i]);
   for(int i = 0; i < a.size(); i ++){
       int tmp = a[i] + k;
       if(rec.find(tmp) != rec.end())
           ans ++;
   }
   return ans;
}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size,_k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}
