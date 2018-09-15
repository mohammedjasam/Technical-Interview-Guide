/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1100],_quicksort_cnt;

int partition(int l, int r){
    int x = a[r], i = l - 1, j, t;
    //x???
    //i ?????(???????????? ???????????)????
    for(j = l; j < r; j++){
        if(a[j] <= x){//??? ??????? ??????????????
            i++;
            t = a[i];a[i] = a[j];a[j] = t;
            _quicksort_cnt ++;
        }
    }
    i++;//?????????????
    t = a[i];a[i] = a[r];a[r] = t;
    _quicksort_cnt ++;
    return i;//???????? ???????????????
}

void quickSort(int l, int r) {
   int q;
    if(l < r){
        q = partition(l, r);//partition//?????????????????
        quickSort(l, q - 1);//????
        quickSort(q + 1, r);//????
        //?????????a[l, r]????????
    }
    return ;
}

void insertSort(vector<int> ar, int &cnt) {
    for(int i = 1; i < ar.size(); i ++){
        int val = ar[i];
        int j = i - 1;
        while(j >= 0 && val < ar[j]) {
            ar[j + 1] = ar[j];
            j --;
            cnt ++;
        }
        ar[j + 1] = val;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    vector<int> _insertsort_ar, _quicksort_ar;
    cin>>n;
    _insertsort_ar.clear();
    _quicksort_ar.clear();
    _quicksort_ar.push_back(-1);
    for(int i = 0; i < n; i ++){
        int tmp;
        cin>>tmp;
        _insertsort_ar.push_back(tmp);
        //_quicksort_ar.push_back(tmp);
        a[i+1] = tmp;
    }
    int _insertsort_cnt = 0;
    _quicksort_cnt = 0;
    insertSort(_insertsort_ar, _insertsort_cnt);
  //  quickSort(_quicksort_ar, 1, n, _quicksort_cnt);
    quickSort(1,n);
 //   cout<<_insertsort_cnt<<endl;
 //   cout<<_quicksort_cnt<<endl;
    cout<<_insertsort_cnt - _quicksort_cnt<<endl;
    return 0;
}
