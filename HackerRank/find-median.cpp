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

void partition(vector<int> rec,int &_accuml, int _tot_len, int &_ans) {
    if(rec.size() <= 1){
        if(_accuml == _tot_len/2)
            _ans = rec[0];
        return ;
    }
    vector<int> _small_rec, _large_rec;
    int val = rec[0];
    for(int i = 1; i < rec.size(); i ++) {
        if(rec[i] <= val)
            _small_rec.push_back(rec[i]);
        else
            _large_rec.push_back(rec[i]);
    }
    if(_accuml + _small_rec.size() == _tot_len/2) {
        _ans = val;
        return ;
    }else if(_accuml + _small_rec.size() > _tot_len/2){
        partition(_small_rec,_accuml,_tot_len,_ans);
    }else{
        _accuml ++;
        _accuml += _small_rec.size();
        partition(_large_rec,_accuml,_tot_len,_ans);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int _ans = 0, _sta = 0;
    vector<int> rec;
    cin>>n;
    for(int i = 0; i < n; i ++){
        int tmp;
        cin>>tmp;
        rec.push_back(tmp);
    }
    partition(rec,_sta,n,_ans);
    cout<<_ans<<endl;
    return 0;
}
