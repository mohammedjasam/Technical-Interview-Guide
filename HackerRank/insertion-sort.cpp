/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void mergeSort(vector<int> &rec, long long &_ans) {
    if(rec.size() <= 1) return ;
    vector<int> _left_rec, _right_rec;
    for(int i = 0; i < rec.size(); i ++) {
        if(i < rec.size()/2)
            _left_rec.push_back(rec[i]);
        else
            _right_rec.push_back(rec[i]);
    }
    mergeSort(_left_rec,_ans);
    mergeSort(_right_rec,_ans);
    int ind = 0, _left_ind = 0, _right_ind = 0;
    while(_left_ind < _left_rec.size() && _right_ind < _right_rec.size()) {
        if(_left_rec[_left_ind] > _right_rec[_right_ind]) {
            _ans += (_left_rec.size() - _left_ind);
            rec[ind ++] = _right_rec[_right_ind];
            _right_ind ++;
        } else {
            rec[ind ++] = _left_rec[_left_ind];
            _left_ind ++;
        }
    }
    while(_left_ind < _left_rec.size()){
        rec[ind ++] = _left_rec[_left_ind];
        _left_ind ++;
    }
    while(_right_ind < _right_rec.size()){
        rec[ind ++] = _right_rec[_right_ind];
        _right_ind ++;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T--) {
        int n;
        long long _ans = 0;
        vector<int> rec;
        cin>>n;
        for(int i = 0; i < n; i ++){
            int tmp;
            cin>>tmp;
            rec.push_back(tmp);
        }
        mergeSort(rec,_ans);
  /*      for(int i = 0; i < rec.size(); i ++)
            cout<<rec[i]<<" ";
        cout<<endl;
        cout<<"--------------------------"<<endl; */
        cout<<_ans<<endl;
    }
    return 0;
}
