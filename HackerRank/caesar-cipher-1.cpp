/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string txt;
int n, k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>n>>txt>>k;
    string ans;
    ans.resize(n);
    for(int i = 0; i < n; ++ i){
        char ch = txt[i];
        int idx;
        if(ch>='a' && ch<='z'){
            idx = ch-'a';
            idx = (idx + k)%26;
            ans[i] = (idx + 'a');
        }else if(ch>='A' && ch<='Z'){
            idx = ch-'A';
            idx = (idx + k)%26;
            ans[i] = (idx + 'A');
        }else
            ans[i] = ch;
    }
    cout<<ans<<endl;
    return 0;
}
