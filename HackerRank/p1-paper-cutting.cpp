/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

long long solve(long long n, long long m){
    long long res = 0;
    if(n <= m)
        res = (n - 1) + n*(m - 1);
    else
        res = (m - 1) + m*(n - 1);
    return res;
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long result = solve(n, m);
    cout << result << endl;
    return 0;
}
