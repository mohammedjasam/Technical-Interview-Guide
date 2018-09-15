/*
*
* Tag: BFS+Binary Search
* Time: O(nlgnlgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000100;
pair<int,int> q[N], preq[N];
long long a[N];
int n, fnt, rear;

int bsearch(long long v, int lbnd, int rbnd){
    long long extsum = lbnd == 0?0:a[lbnd - 1];
    int l = lbnd, r = rbnd;
    while(l <= r){
        int mid = (l + r)>>1;
        long long val = a[mid] - extsum;
        if(val == v)
            return mid;
        else if(val < v)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        bool allzero = true;
        for(int i = 0; i < n; ++ i){
            scanf("%lld",&a[i]);
            if(a[i])
                allzero = false;
        }
        if(allzero){
            printf("%d\n",n-1);
            continue;
        }
        for(int i = 1; i < n; ++ i)
            a[i] += a[i - 1];
        int ans = 0;
        fnt = rear = 0;
        q[rear ++] = make_pair(0, n - 1);
        while(fnt < rear){
            int pfnt = 0, prear = 0;
            while(fnt < rear){
                pair<int,int> cur = q[fnt ++];
                long long sum = a[cur.second] - (cur.first == 0?0:a[cur.first - 1]);
                int fid = -1;
                if(sum%2 == 1)
                    continue;
                fid = bsearch(sum/2, cur.first, cur.second);
                if(fid == -1)
                    continue;
                preq[prear ++] = make_pair(cur.first, fid);
                preq[prear ++] = make_pair(fid + 1, cur.second);
            }
            for(int i = pfnt; i < prear; ++ i)
                q[rear ++] = preq[i];
            ++ ans;
        }
        printf("%d\n",ans - 1);
    }
    return 0;
}
