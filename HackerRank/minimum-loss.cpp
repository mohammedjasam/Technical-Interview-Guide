/*
*
* Tag: Data Structure
* Time: O(nlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1000100;
int n;
long long arr[N], ans;
map<long long, int> dict;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ans = LLONG_MAX;
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i){
        scanf("%lld",&arr[i]);
        ++ dict[arr[i]];
    }
    map<long long, int>::iterator it;
    for(int i = 0; i < n; ++ i){
        it = dict.lower_bound(arr[i]);
        if(it != dict.begin()){
            -- it;
            ans = min(ans, arr[i] - it->first);
        }
        -- dict[arr[i]];
        if(dict[arr[i]] == 0)
            dict.erase(arr[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
