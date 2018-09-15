#include <cmath>
#include <cstdio>
/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(n)
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> seq;
int n, q, lastans;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&q);
    seq.resize(n);
    lastans = 0;
    while(q --){
        int t, x, y, id;
        scanf("%d%d%d",&t,&x,&y);
        id = (x^lastans)%n;
        if(t == 1){
            seq[id].push_back(y);
        }else{
            int m = seq[id].size();
            lastans = seq[id][y%m];
            printf("%d\n",lastans);
        }
    }
    return 0;
}
