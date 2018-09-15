/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string tim;
string ans;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cin>>tim;
    ans="";
    int h = 0;
    h = (tim[0] - '0');
    h = h*10 + (tim[1] - '0');
    if(tim[8] == 'P' && !(tim[0]=='1' && tim[1]=='2'))
      h = (h + 12)%24;
    else if(tim[8] == 'A' && (tim[0]=='1' && tim[1]=='2'))
        h = 0;
    ans += (h/10 + '0');
    ans += (h%10 + '0');
    for(int i = 2; i < 8; ++ i)
        ans += tim[i];
    cout<<ans<<endl;
    return 0;
}
