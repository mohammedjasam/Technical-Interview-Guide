/*
*
* Tag: Data Structure (Binary Index Tree)
* Time: O(nlgn)
* Space: O(n)
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<int> bidx;

int lowbit(int x){
    return x&-x;
}

int sumup(int v){
    int res = 0;
    for(int i = v; i > 0; i -= lowbit(i))
        res += bidx[i];
    return res;
}

void update(int v, int n){
    for(int i = v; i <= n; i += lowbit(i))
        ++ bidx[i];
}

int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
           cin >> q[q_i];
        }
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            if(q[i] > i + 1){
                if(q[i] - i - 1 > 2){
                    ans = -1;
                    break;
                }
            }
        }
        if(ans == -1){
            puts("Too chaotic");
        }else{
            bidx.resize(n + 1);
            for(int i = n - 1; i >= 0; -- i){
                ans += sumup(q[i]);
                update(q[i], n);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
