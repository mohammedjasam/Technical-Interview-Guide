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
struct element {
    int val,indx;
    string ss;
    bool isdash;
    bool operator < (const element a) const {
        if(val == a.val)
            return indx < a.indx;
        return val < a.val;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    element elem;
    vector<element> rec;
    cin>>n;
    for(int i = 0; i < n; i ++) {
        cin>>elem.val>>elem.ss;
        elem.indx = i;
        if(i < n/2) 
            elem.isdash = true;
        else
            elem.isdash = false;
        rec.push_back(elem);
    }
    sort(rec.begin(),rec.end());
    for(int i = 0; i < n; i ++){
        if(rec[i].isdash)
            cout<<"-";
        else
            cout<<rec[i].ss;
        cout<<" ";
    }
    cout<<endl;
    return 0;
}
