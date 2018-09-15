/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        if(n <= 10)
            return -1;
        string v = to_string(n);
        next_permutation(begin(v), end(v));
        long long ans = stoll(v);
        return (ans > INT_MAX || ans <= n) ? -1 : (int)ans;
    }
};
