/*
*
* Tag: Binary Search
* Time: O(lg(n + m))
* Space: O(1g(n + m))
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int m = A.size(), n = B.size();
        int tot = m + n;
        int Ary[m], Bry[n];
        for(int i = 0; i < m; ++ i)
            Ary[i] = A[i];
        for(int i = 0; i < n; ++ i)
            Bry[i] = B[i];
        if(tot%2)
            return find_median(Ary, m, Bry, n, tot/2 + 1);
        else
            return (find_median(Ary, m, Bry, n, tot/2) + find_median(Ary, m, Bry, n, tot/2 + 1))/2.0;
    }
    
    int find_median(int A[], int m, int B[], int n, int k){
        if(m > n) return find_median(B, n, A, m, k);
        if(m == 0) return B[k - 1];
        if(k == 1) return min(A[0], B[0]);
        
        int ia = min(k/2, m), ib = k - ia;
        if(A[ia - 1] < B[ib - 1])
            return find_median(A + ia, m - ia, B, n, k - ia);
        else if(A[ia - 1] > B[ib - 1])
            return find_median(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];
    }
};

