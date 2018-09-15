/*
*
* Tag: Greedy
* Time: O(n*mlgm)
* Space: O(nm)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T --){
        cin>>n;
        string grid[n];
        for(int i = 0; i < n; ++ i){
            cin>>grid[i];
            sort(grid[i].begin(), grid[i].end());
        }
        bool issort = true;
        int m = grid[0].size();
        for(int i = 0; i < m; ++ i){
            for(int j = 1; j < n; ++ j){
                if(grid[j - 1][i] > grid[j][i]){
                    issort = false;
                    break;
                }
            }
            if(!issort)
                break;
        }
        if(issort)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
