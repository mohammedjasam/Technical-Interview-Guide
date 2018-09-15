/*
*
* Tag: Implementation
* Time: O(n^2)
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
    int ans = 0;
    vector<int> rec;
    cin>>n;
    for(int i = 0; i < n; i ++){
        int tmp;
        cin>>tmp;
        rec.push_back(tmp);
        for(int j = 0; j < i; j ++){
            if(rec[j] > tmp)
                ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
