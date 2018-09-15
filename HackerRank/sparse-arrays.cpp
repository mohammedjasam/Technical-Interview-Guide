/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n, q;
unordered_map<string, int> dict;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>n;
    for(int i = 0; i < n; ++ i){
        string s;
        cin>>s;
        if(dict.find(s) == dict.end())
            dict[s] = 1;
        else
            ++ dict[s];
    }
    cin>>q;
    while(q --){
        string t;
        cin>>t;
        if(dict.find(t) != dict.end())
            cout<<dict[t]<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}
