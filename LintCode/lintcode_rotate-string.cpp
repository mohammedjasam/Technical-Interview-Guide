/*
*
* Tag: String (Brute Force)
* Time: O(n) (n is the length of string)
* Space: O(1)
*/
class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        string ans = "";
        if(!A.size())
            return ans;
        int n = A.size(), i = 0;
        offset = offset%n;
        int idx = (n - offset)%n;
        for(; i < n; ++ i){
            ans += A[idx];
            idx = (idx + 1)%n;
        }
        return ans;
    }
};
