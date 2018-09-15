/*
*
* Tag: Implementation
* Time: O(n)
* Space: 
*/
#include <bits/stdc++.h>
using namespace std;
string s, t = "hackerrank";
int i, j;

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        cin>>s;
        i = j = 0;
        for(i = 0; i < s.size() && j < t.size(); ++ i){
            if(s[i] == t[j])
                ++ j;
        }
        if(j >= t.size())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
