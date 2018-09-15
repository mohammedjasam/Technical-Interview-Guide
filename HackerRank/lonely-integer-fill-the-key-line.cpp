/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
#include <bits/stdc++.h> 

using namespace std;

int lonely_integer(vector < int > a) {
    int answer = 0;
    for(int i = 0; i < a.size(); i++) {
         // FILL THE MISSING LINE HERE
    }
    return answer;
}

int main() {
    int res;
    int _a_size;
    cin >> _a_size;
    vector <int> _a(_a_size);
    for(int _a_i = 0; _a_i < _a_size; _a_i++) {
        cin >> _a[_a_i];
    }
    res = lonely_integer(_a);
    cout << res;
    return 0;
}

