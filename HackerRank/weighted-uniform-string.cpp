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
#include <unordered_set>
using namespace std;
string s;
int n;
unordered_set<int> st;

void init(){
    char pre = 0;
    int sum = 0;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] != pre){
            pre = s[i];
            sum = 0;
        }
        sum += ((s[i] - 'a') + 1);
        st.insert(sum);
    }
}

int main(){
    cin >> s >> n;
    init();
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if(st. find(x) == st.end())
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
