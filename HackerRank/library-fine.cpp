/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include <cstdio>
#include <vector>
using namespace std;
int d1, m1, y1, d2, m2, y2;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d%d%d%d%d",&d1,&m1,&y1,&d2,&m2,&y2);
    int ans = 0;
    if(y1 > y2)
        ans = 10000;
    else{
        if(y1 == y2 && m1 > m2)
            ans = 500*(m1 - m2);
        else{
            if(y1 == y2 && m1 == m2 && d1 > d2)
                ans = 15*(d1 - d2);
        }
    }
    printf("%d\n",ans);
    return 0;
}
