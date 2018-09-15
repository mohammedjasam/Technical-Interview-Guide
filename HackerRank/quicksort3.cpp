/*
*
* Tag: Sorting
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&arr[i]);
    stack<pair<int,int> > sta;
    sta.push(make_pair(0, n - 1));
    while(!sta.empty()){
        pair<int,int> range = sta.top();
        sta.pop();
        int pos = range.first - 1;
        int pivot = arr[range.second];
        for(int i = range.first; i <= range.second; ++ i){
            if(arr[i] < pivot){
                swap(arr[i], arr[++ pos]);
            }
        }
        swap(arr[++ pos],arr[range.second]);
        for(int i = 0; i < n; ++ i)
            printf("%d ",arr[i]);
        puts("");
        if(pos + 1 < range.second){
            sta.push(make_pair(pos+1,range.second));
        }
        if(pos - 1 > range.first){
            sta.push(make_pair(range.first, pos - 1));
        }
    }
    return 0;
}
