/*
*
* Tag: DFS
* Time: ?
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    while(n --){
        string s, t, p;
        cin>>s;
        t = s;
        p = s;
        sort(p.begin(),p.end(),greater<char>());
        if(p == s){
            cout<<"no answer"<<endl;
            continue;
        }
        while (next_permutation(s.begin(),s.end())){
            break;
        }
        if(t == s)
            cout<<"no answer"<<endl;
        else
            cout<<s<<endl;
    }
    return 0;
}
