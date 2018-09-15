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
    vector<int> rec(101,0);
    cin>>n;
    for(int i = 0; i < n; i ++){
        int a;
        cin>>a;
        rec[a] ++;
    }
    for(int i = 0; i < 100; i ++){
        cout<<rec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
