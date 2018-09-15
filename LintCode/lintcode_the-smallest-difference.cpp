/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        int ans;
        if(!A.size() && !B.size())
            return 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if(!A.size())
            return B[0];
        if(!B.size())
            return A[0];
        int n = A.size(), m = B.size(), ia = 0, ib = 0;
        ans = INT_MAX;
        while(ia < n){
            while(ib < m && A[ia] >= B[ib]){
                ans = min(ans, abs(A[ia] - B[ib]));
                ++ ib;
            }
            ans = min(ans, abs(A[ia] - B[ib]));
            ++ ia;
        }
        return ans;
    }
};

