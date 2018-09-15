/*
*
* Tag: Geometry
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
pair<int,int> btnl, upr, pnt[N];
int n, q;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&q);
    while(q --){
        scanf("%d",&n);
        btnl.first = btnl.second = INT_MAX;
        upr.first = upr.second = INT_MIN;
        for(int i = 0; i < n; ++ i){
            scanf("%d%d",&pnt[i].first,&pnt[i].second);
            btnl.first = min(btnl.first, pnt[i].first);
            btnl.second = min(btnl.second, pnt[i].second);
            upr.first = max(upr.first, pnt[i].first);
            upr.second = max(upr.second, pnt[i].second);
        }
        if(n <= 2){
            puts("YES");
            continue;
        }
        bool hasOutPnt = false;
        for(int i = 0; i < n; ++ i){
            if(! ( ( (pnt[i].first >= btnl.first && pnt[i].first <= upr.first) &&(pnt[i].second == btnl.second || pnt[i].second == upr.second) ) || ( (pnt[i].second >= btnl.second && pnt[i].second <= upr.second) &&(pnt[i].first == btnl.first || pnt[i].first == upr.first ) ) ) ){
                hasOutPnt = true;
                break;
            }
        }
        if(hasOutPnt){
            puts("NO");
        }else{
            puts("YES");
        }
    }
    return 0;
}
