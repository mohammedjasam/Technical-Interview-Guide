/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b){
    return a.size() == b.size()? a < b : a.size() < b.size();
}

int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    sort(unsorted.begin(), unsorted.end(), cmp);
    for(int i = 0; i < n; ++ i)
        cout<<unsorted[i]<<endl;
    return 0;
}
