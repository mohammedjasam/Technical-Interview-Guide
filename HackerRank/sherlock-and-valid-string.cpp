/*
*
* Tag: Implementation or Hash
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int N = 100010;
char s[N];
int cnt[30];
unordered_set<int> st;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%s",s);
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; s[i]; ++ i){
        ++ cnt[s[i] - 'a'];
    }
    for(int i = 0; i < 26; ++ i){
        if(cnt[i])
            st.insert(cnt[i]);
    }
    if(st.size() <= 1){
        puts("YES");
    }else if(st.size() > 2){
        puts("NO");
    }else{
        bool isfind = false;
        for(int i = 0; i < 26; ++ i){
            if(cnt[i]){
                -- cnt[i];
                st.clear();
                for(int j = 0; j < 26; ++ j){
                    if(cnt[j])
                        st.insert(cnt[j]);
                }
                if(st.size() <= 1){
                    isfind = true;
                    break;
                }
                ++ cnt[i];
            }
        }
        if(isfind)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
