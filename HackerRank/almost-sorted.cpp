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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    vector<int> sortarr(n), revarr(n);
    for(int i = 0; i < n; ++ i){
        scanf("%d",&arr[i]);
        sortarr[i] = arr[i];
    }
    bool isasc = true;
    for(int i = 1; i < n; ++ i){
        if(arr[i] < arr[i - 1]){
            isasc = false;
            break;
        }
    }
    if(isasc){
        puts("yes");
        return 0;
    }
    sort(sortarr.begin(), sortarr.end());
    int difcnt = 0, sta = 0, ends = 0;
    for(int i = 0; i < n; ++ i){
        if(sortarr[i] != arr[i]){
            difcnt ++;
            if(difcnt == 1)
                sta = i;
            else if(difcnt == 2)
                ends = i;
        }
    }
    if(difcnt == 2){
        puts("yes");
        printf("swap %d %d\n",sta + 1, ends + 1);
        return 0;
    }
    for(int i = 0; i < n; ++ i){
        if(sortarr[i] != arr[i]){
            sta = i;
            break;
        }
    }
    for(int i = n - 1; i > sta; -- i){
        if(sortarr[i] != arr[i]){
            ends = i;
            break;
        }
    }
    int id = 0;
    for(int i = 0; i < sta; ++ i, ++ id)
        revarr[id] = arr[i];
    for(int i = ends; i >= sta; -- i, ++ id)
        revarr[id] = arr[i];
    for(int i = ends + 1; i < n; ++ i, ++ id)
        revarr[id] = arr[i];
    isasc = true;
    for(int i = 0; i < n; ++ i){
        if(sortarr[i] != revarr[i]){
            isasc = false;
            break;
        }
    }
    if(isasc){
        puts("yes");
        printf("reverse %d %d\n",sta + 1, ends + 1);
    }else{
        puts("no");
    }
    return 0;
}
