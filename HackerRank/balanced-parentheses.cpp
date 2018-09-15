/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1100;
string s;
char stk[N];
int top;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T --){
        top = 0;
        cin>>s;
        for(int i = 0; i < s.size(); ++ i){
            if(!top)
                stk[top ++] = s[i];
            else{
                switch(s[i]){
                    case '(':stk[top ++] = s[i];
                          break;
                    case '{': stk[top ++] = s[i];
                          break;
                    case '[': stk[top ++] = s[i];
                          break;
                    case ')': if(stk[top - 1] == '(')
                            -- top;
                           else
                               stk[top ++] = s[i];
                            break;
                    case '}': if(stk[top - 1] == '{')
                            -- top;
                           else
                               stk[top ++] = s[i];
                            break;
                    case ']': if(stk[top - 1] == '[')
                            -- top;
                           else
                               stk[top ++] = s[i];
                            break;
                }
            }
        }
        if(!top)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
