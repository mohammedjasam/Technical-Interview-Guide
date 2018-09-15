/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
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
int N;
vector<int> B;

int main(){
    cin >> N;
    B.resize(N+3);
    for(int B_i = 0;B_i < N;B_i++){
       cin >> B[B_i];
    }
    int ans = 0;
    for(int i = 0; i < N; ++ i){
        if(B[i]%2 == 1){
            if((i > 0 && B[i - 1]%2 == 1) || i == N - 1){
                ++ B[i - 1];
                ++ B[i];
            }else if(i == 0 || B[i - 1]%2 == 0){
                ++ B[i + 1];
                ++ B[i];
            }
            ++ ans;
        }
    }
    bool alleven = true;
    for(int i = 0; i < N; ++ i){
        if(B[i]%2 == 1){
            alleven = false;
            break;
        }
    }
    if(!alleven)
        puts("NO");
    else
        printf("%d\n",ans*2);
    return 0;
}
