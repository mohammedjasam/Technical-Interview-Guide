/*
*
* Tag: Game Theory
* Time: O(n)
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
const int N = 200100;
const int M = 100100;
bool unprime[N];
int prime[N], primecnt[M];
int n, num;

void init(){
    num = 0;
    memset(unprime, 0, sizeof(unprime));
    memset(primecnt, 0, sizeof(primecnt));
    for(int i = 2 ; i < N ; ++ i){ 
        if(!unprime[i])                 
            prime[num ++]=i;    
        for(int j = 0 ; j < num && i * prime[j] <  N ; ++ j)  {                 
                unprime[i*prime[j]] = 1;    
            if(!(i % prime[j] ))                    
                break;             
        }          
    }
    int id = 0;
    for(int i = 2; i < M; ++ i){
        primecnt[i] = primecnt[i - 1];
        if(i == prime[id]){
            ++ primecnt[i];
            ++ id;
        }
    }
}

int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        if(primecnt[n]%2 == 1)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}
