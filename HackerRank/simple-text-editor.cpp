/*
*
* Tag: Data Structure (Stack)
* Time: O(nm)
* Space: O(m)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 1010100;
const int N = 100001;
string opstk[M];
char tmpstr[N];
string tmpstrs, str;
int optop, k;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    optop = 0;
    int q, len;
    scanf("%d",&q);
    while(q --){
        int op;
        scanf("%d",&op);
        switch(op){
            case 1:
                scanf("%s",tmpstr);
                if(optop)
                   str = opstk[optop - 1];
                else
                    str = "";
                str += string(tmpstr);
                opstk[optop ++] = str;
                break;
            case 2:
                scanf("%d",&k);
                if(!optop)
                    break;
                tmpstrs =opstk[optop - 1];
                len = tmpstrs.size() - k;
                if(len <= 0)
                    str = "";
                else
                    str = tmpstrs.substr(0, len);
                opstk[optop ++] = str;
                break;
            case 3:
                scanf("%d",&k);
                if(!optop)
                    break;
                str = opstk[optop - 1];
                if(str.size() != 0)
                    putchar(str[k - 1]);
                puts("");
                break;
            case 4:
                if(!optop)
                    break;
                -- optop;
                break;
        }
    }
    return 0;
}
