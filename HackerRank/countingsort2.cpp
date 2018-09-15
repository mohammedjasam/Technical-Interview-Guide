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
    int tmp;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> tmp;
        rec[tmp] ++;
    }
    for(int i = 0; i < 100; i ++){
        for(int j = 0; j < rec[i]; j ++)
            cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
