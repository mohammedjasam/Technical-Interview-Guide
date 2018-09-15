/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area){
    if(area%base == 0 || (2*area)%base == 0)
        return 2*area/base;
    int mod_v = (2*area)%base;
    return (2*area + (base - mod_v))/base;
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}
