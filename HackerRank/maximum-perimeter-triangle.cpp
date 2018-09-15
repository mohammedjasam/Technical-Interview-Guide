/*
*
* Tag: Math
* Time: O(n^3)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;
int arr[N], n, side[3];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d",&n);
    for(int i = 0; i < n; ++ i)
        scanf("%d",&arr[i]);
    sort(arr, arr + n);
    int ans = -1;
    for(int i = n - 1; i >= 2; -- i){
        for(int j = i - 1; j >= 1; -- j){
            for(int k = j - 1; k >= 0; -- k){
                if(arr[k] + arr[j] > arr[i]){
                    ans = arr[k] + arr[j] + arr[i];
                    side[0] = arr[k];
                    side[1] = arr[j];
                    side[2] = arr[i];
                    break;
                }
            }
            if(ans != -1)
                break;
        }
        if(ans != -1)
            break;
    }
    if(ans == -1)
        puts("-1");
    else{
        printf("%d %d %d\n",side[0],side[1],side[2]);
    }
    return 0;
}
