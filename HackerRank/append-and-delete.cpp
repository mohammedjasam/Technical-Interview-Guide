/*
*
* Tag: Implementation or Greedy
* Time: O(n)
* Space: O(1)
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 1100;
string s, t;
int k, n, m;

int main(){
    cin>>s>>t>>k;
    n = s.size(), m = t.size();
    if(s == t){
        if(k%2 == 0 || k >= 2*n)
            k = 0;
    }else{
        if(k == 0)
            k = 1;
        else{
            if(n > m){
                k -= (n - m);
                n = m;
            }
            int i = 0, j = 0;
            while(i < n || j < m){
                if(i >= n){
                    -- k;
                    ++ j;
                }else{
                    if(s[i] != t[j]){
                        k -= ((n - i) + (m - i));
                        if(i == 0 && k >= 0)
                            k = 0;
                        i = n, j = m;
                    }
                    ++ i, ++ j;
                }
                
                if(k < 0)
                    break;
            }
            if(k >= 0){
                if(n < m)
                    n = m;
                if(k%2 == 0 || k >= 2*n)
                    k = 0;
                else
                    k = 1;
            }
        }
    }
    if(k == 0)
        puts("Yes");
    else
        puts("No");
    return 0;
}
