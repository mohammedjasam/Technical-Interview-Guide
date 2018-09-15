/*
*
* Tag: Data Structure
* Time: O(kdlgd)
* Space: O(k)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N = 300000;
int n, d, v, arr[N];
multiset<int> lwst, upst;
multiset<int>::iterator it;

void adjustSet(){
    if(lwst.size() == 0)
        return ;
    int u = 0, v = 0;
    if(d%2){
        while(lwst.size() < upst.size() + 1 && upst.size() > 0){
            v = (*(upst.begin()));
            lwst.insert(v);
            upst.erase(upst.begin());
        }
        
        while(lwst.size() > upst.size() + 1 && lwst.size() > 0){
            v = (*(lwst.rbegin()));
            upst.insert(v);
            it = lwst.find(v);
            lwst.erase(it);
        }
    }else{
        while(lwst.size() < upst.size() && upst.size() > 0){
            v = (*(upst.begin()));
            lwst.insert(v);
            upst.erase(upst.begin());
        }
        
        while(lwst.size() > upst.size() && lwst.size() > 1){
            v = (*(lwst.rbegin()));
            upst.insert(v);
            it = lwst.find(v);
            lwst.erase(it);
        }
    }
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&n,&d);
    int ans = 0, lw_val = 0, up_val = 0;
    lwst.clear();
    upst.clear();
    for(int i = 0; i < n; ++ i){
        scanf("%d",&arr[i]);
        if(i >= d){
            lw_val = *(lwst.rbegin());
            up_val = *(upst.begin());
            if(d%2){
                ans += arr[i] >= 2*lw_val?1:0;
            }else{
                ans += arr[i] >= (lw_val + up_val)?1:0;
            }
            v = arr[i - d];
            it = lwst.find(v);
            if(it != lwst.end()){
                lwst.erase(it);
            }else{
                it = upst.find(v);
                upst.erase(it);
            }
        }
        if(lwst.size() == 0 || *(lwst.rbegin()) >= arr[i])
            lwst.insert(arr[i]);
        else
            upst.insert(arr[i]);
        adjustSet();
    }
    printf("%d\n",ans);
    return 0;
}
