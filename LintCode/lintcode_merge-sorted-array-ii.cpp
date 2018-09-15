class Solution {
public:
/*
*
* Tag: Array (Brute Force)
* Time: O(n)
* Space: O(1)
*/
/**
 * @param A and B: sorted integer array A and B.
 * @return: A new sorted integer array
 */
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    // write your code here
    vector<int> ans;
    if(!A.size() && !B.size())
        return ans;
    if(!A.size())
        return B;
    if(!B.size())
        return A;
    int ia = 0, ib = 0, ic = 0;
    ans.resize(A.size() + B.size());
    for(; ia < A.size() && ib < B.size(); ){
        if(A[ia] <= B[ib])
            ans[ic ++] = A[ia ++];
        else
            ans[ic ++] = B[ib ++];
    }
    while(ia < A.size()) ans[ic ++] = A[ia ++];
    while(ib < B.size()) ans[ic ++] = B[ib ++];
    return ans;
}
};
