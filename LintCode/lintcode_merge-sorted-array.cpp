/*
*
* Tag: Brute Force
* Time: O(n + m)
* Space: O(n + m)
*/
class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        if(!n)
            return ;
        if(!m){
            for(int i = 0; i < n; ++ i)
                A[i] = B[i];
            return ;
        }
        for(int i = m; i < m + n; ++ i)
            A[i] = B[i - m];
        int p1 = m - 1, p2 = n - 1;
        for(int idx = m + n - 1; idx >= 0; -- idx){
            int vala = A[p1], valb = B[p2];
            if(p1>= 0 && p2 < 0){
                A[idx] = vala;
                -- p1;
            }else if(p1 < 0 && p2 >= 0){
                A[idx] = valb;
                -- p2;
            }else{
                if(vala > valb){
                    A[idx] = vala;
                    -- p1;
                }else{
                    A[idx] = valb;
                    -- p2;
                }
            }
        }
        return ;
    }
};
