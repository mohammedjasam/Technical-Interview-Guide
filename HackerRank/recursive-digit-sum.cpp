/*
*
* Tag: Math
* Time: O(nlgn)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int k;
long long v, u;

void init(){
    v = 0;
    for(int i = 0; i < s.size(); ++ i)
        v += (s[i] - '0');
    v *= k;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>s>>k;
    init();
    while(v >= 10){
        u = 0;
        while(v > 0){
            u += (v%10);
            v /= 10;
        }
        v = u;
    }
    cout<<v<<endl;
    return 0;
}
