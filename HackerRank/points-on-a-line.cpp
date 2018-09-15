/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20;
int n;
pair<int,int> pnt[N];

bool allVertical(){
    for(int i = 1; i < n; ++ i){
        if(pnt[i].first != pnt[i - 1].first)
            return false;
    }
    return true;
}

bool allHorizontal(){
    for(int i = 1; i < n; ++ i){
        if(pnt[i].second != pnt[i - 1].second)
            return false;
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%d%d",&pnt[i].first,&pnt[i].second);
    if(allVertical() || allHorizontal())
        puts("YES");
    else
        puts("NO");
    return 0;
}
