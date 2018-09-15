/*
*
* Tag: Implementation, Hash
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
    int v,n;
    vector<int> rec;
    cin>>v>>n;
    for(int i = 0; i < n; i ++){
        int tmp;
        cin>>tmp;
        rec.push_back(tmp);
    }
    for(int i = 0; i < n; i ++){
        if(rec[i] == v){
           cout<<i<<endl;
           break;
        }
    }
    return 0;
}
