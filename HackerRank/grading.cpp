/*
*
* Tag: Implementation
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


int main(){
    int n, v;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int grade;
        cin >> grade;
        if(grade >= 38){
            v = grade%10;
            if(v >= 3 && v <= 5)
                grade += (5 - v);
            else if(v >= 8)
                grade += (10 - v);
        }
        cout<<grade<<endl;
    }
    return 0;
}
