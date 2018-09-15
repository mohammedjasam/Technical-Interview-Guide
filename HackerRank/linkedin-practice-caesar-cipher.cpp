/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1100;
char s[N];
int n,k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%s%d",&n,s,&k);
    char v;
    int idx;
    for(int i = 0; s[i]; ++ i){
        v = s[i];
        if(s[i] >= 'a' && s[i] <= 'z'){
            v = (((s[i] - 'a') + k)%26 + 'a');
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            v = (((s[i] - 'A') + k)%26 + 'A');
        }
        s[i] = v;
    }
    puts(s);
    return 0;
}
