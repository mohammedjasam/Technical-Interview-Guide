/*
*
* Tag: Brute Force
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
#include <unordered_set>
using namespace std;
const int N = 1100;
char s[N];
unordered_set<char> st;
pair<char,char> u;
int n, ans;

void solve(pair<int,int> u){
    int cnt = 0;
    bool isfirst = true;
    for(int i = 0; s[i]; ++ i){
        if(isfirst){
            if(s[i] == u.first){
                isfirst = false;
                ++ cnt;
            }else if(s[i] == u.second)
                return;
        }else{
            if(s[i] == u.second){
                isfirst = true;
                ++ cnt;
            }else if(s[i] == u.first)
                return;
        }
    }
    
    ans = max(ans, cnt);
}

int main(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i = 0; s[i]; ++ i)
        st.insert(s[i]);
    unordered_set<char>::iterator i, j;
    ans = 0;
    for(i = st.begin(); i != st.end(); ++ i){
        j = i;
        for(++ j; j != st.end(); ++ j){
            u = make_pair(*i,*j);
            solve(u);
            u = make_pair(*j,*i);
            solve(u);
        }
    }
    printf("%d\n",ans);
    return 0;
}
