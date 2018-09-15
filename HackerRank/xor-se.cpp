/*
*
* Tag: Bit Manipulation
* Time: O(1)
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
int a[8]={0,1,2,2,6,7,0,0};

int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        long long L;
        long long R;
        cin >> L >> R;
        long long ansl = 0, ansr = 0;
        if(L)
            -- L;
        if(L%8 != 6 && L%8 != 7 && L%8 != 2 && L%8 != 3){
          ansl = a[L%8]+(L/8)*8;  
        }else if(L%8 == 2 || L%8 == 3){
            ansl = 2;
        }
        if(R%8 != 6 && R%8 != 7 && R%8 != 2 && R%8 != 3){
          ansr = a[R%8]+(R/8)*8;  
        }else if(R%8 == 2 || R%8 == 3){
            ansr = 2;
        }
        printf("%lld\n",ansr^ansl);
    }
    return 0;
}
