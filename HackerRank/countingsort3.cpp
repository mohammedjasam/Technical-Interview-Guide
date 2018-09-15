/*
*
* Tag: Sort
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    vector<int> rec(100,0);
    cin>>n;
    for(int i = 0; i < n; i ++){
        int _tmpnum;
        string _tmpstring;
        cin>>_tmpnum>>_tmpstring;
        rec[_tmpnum] ++;
    }
    for(int i = 0; i < 100; i ++) {
        if(!i) 
            cout<<rec[i]<<" ";
        else{
            rec[i] += rec[i - 1];
            cout<<rec[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
