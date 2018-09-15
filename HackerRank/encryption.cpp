/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(nm)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string msg;
    int _num_r,_num_c;
    int len = 0, id = 0;
    vector<string> _chy_text;
    cin>>msg;
    len = msg.size();
    _num_r = sqrt(len*1.0);
    _num_c = ceil(sqrt(len*1.0));
    if(_num_r*_num_c < len)
        _num_r ++;
    for(int i = 0; i < _num_r; i ++){
        string tmp="";
        _chy_text.push_back(tmp);
        for(int j = 0; j < _num_c; j ++){
            _chy_text[i] += msg[id];
            ++ id;
            if(id == len) break;
        }
    }
    for(int i = 0; i < _num_c; i ++) {
        for(int j = 0; j < _num_r; j ++) {
            if(i < _chy_text[j].size())
                cout<<_chy_text[j][i];
        }
        cout<<" ";
    }
    cout<<endl;
    return 0;
}
