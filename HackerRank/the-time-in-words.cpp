/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> dic = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight", "twenty nine","half"};
int h, m;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d%d",&h,&m);
    string hh, mm;
    hh = dic[h];
    if(m == 0)
        cout<<hh<<" o' clock"<<endl;
    else if(m <= 30){
        mm = dic[m];
        if(m == 1)
            mm += " minute";
        else if(m != 15 && m != 30)
            mm += " minutes";
        cout<<mm<<" past "<<hh<<endl;
    }else{
        m = 60 - m;
        mm = dic[m];
        hh = dic[h + 1];
        if(m == 1)
            mm += " minute";
        else if(m != 15)
            mm += " minutes";
        cout<<mm<<" to "<<hh<<endl;
    }
    return 0;
}
