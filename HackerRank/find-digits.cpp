/*
*
* Tag: Implementation
* Time: O(lgn)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T--) {
        vector<bool> vis(10,false);
        int val, tmpval, cnt = 0;
        string _digs = "";
        cin>>val;
        tmpval = val;
        while(tmpval) {
            int _addval = tmpval%10;
            tmpval /= 10;
            _digs += (_addval + '0');
        }
        for(int i = 0; i < _digs.size(); i ++) {
            int _div = (_digs[i] - '0');
            if(_div != 0) {
                if(val % _div == 0)
                    cnt ++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
