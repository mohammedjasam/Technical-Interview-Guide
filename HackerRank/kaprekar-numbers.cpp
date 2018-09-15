/*
*
* Tag: Math
* Time: O(lgn)
* Space: O(n)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<long long> table, ans;
int p, q;

long long Cal(long long n, long long m){
    string s = "";
    long long ans = 0, val = m;
    int d = 0;
    while(m){
        ++ d;
        m /= 10;
    }
    while(n){
        s += (n%10 + '0');
        n/=10;
    }
    reverse(s.begin(), s.end());
    int i = s.size() - d;
    long long l = 0, r = 0;
    for(; i < s.size(); ++ i){
        l = l*10 + (s[i] - '0');
    }
    for(i = 0; i < s.size() - d; ++ i){
        r = r*10 + (s[i] - '0');
    }
    return val == (l + r);
}

void init(){
    table.push_back(1);
    table.push_back(9);
    for(long long i = 10; i <= 100000; ++ i){
        long long sq = i*i;
        if(Cal(sq, i))
            table.push_back(i);
    }
}

bool check(){
    int i = 0;
    while(table[i] < p) ++ i;
    while(table[i] >= p && table[i] <= q){
        ans.push_back(table[i]);
        ++ i;
    }
    return ans.size() != 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    init();
    scanf("%d%d",&p,&q);
    if(q < p || !check())
        puts("INVALID RANGE");
    else{
        for(int i = 0; i < ans.size(); ++ i)
            printf("%lld ",ans[i]);
        puts("");
    }
    return 0;
}
