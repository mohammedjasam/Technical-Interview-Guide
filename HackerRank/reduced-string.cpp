/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
char s[N], t[N];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%s",s);
    while(1){
        bool ischange = false;
        int idx = 0;
        memset(t, 0, sizeof(t));
        for(int i = 0; s[i]; ++ i){
            if(s[i] == s[i + 1]){
                ++ i;
                ischange = true;
            }else{
                t[idx ++] = s[i];
            }
        }
        strcpy(s, t);
        if(!ischange){
            break;
        }
    }
    if(strlen(t) == 0)
        puts("Empty String");
    else
        puts(t);
    return 0;
}
