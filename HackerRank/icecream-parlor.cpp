/*
*
* Tag: Binary Search + Sort
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct num {
    int val, id;
    bool operator < (const num a) const {
        if(val == a.val)
            return id < a.id;
        return val<a.val;
    }
};

int binarySearch(int sta, vector<num> rec, int goal) {
    int l = sta, r = rec.size() - 1;
    while(l <= r) {
        int mid = (l + r)>>1;
        if(rec[mid].val == goal)
            return mid;
        else if(rec[mid].val < goal)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T --) {
        int c,l;
        vector<num> rec;
        cin>>c>>l;
        for(int i = 0; i < l; i ++) {
            num tmp;
            cin>>tmp.val;
            tmp.id = i + 1;
            rec.push_back(tmp);
        }
        sort(rec.begin(),rec.end());
        for(int i = 0; i < rec.size(); i ++){
            int ans = binarySearch(i + 1, rec, c - rec[i].val);
            if(ans != -1){
                int _lid = min(rec[i].id,rec[ans].id);
                int _rid = max(rec[i].id,rec[ans].id);
                cout<<_lid<<" "<<_rid<<endl;
            }
        }
    }
    return 0;
}
