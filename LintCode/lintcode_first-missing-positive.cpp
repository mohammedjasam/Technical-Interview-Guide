/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        if(A.size() == 0)
            return 1;
        int n = A.size();
        for(int i = 0; i < n; ++ i){
            while(A[i] != i + 1){
                if(A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                swap(A[i], A[A[i] - 1]);
            }
        }
        for(int i = 0; i < n; ++ i){
            if(i+1 != A[i])
                return i+1;
        }
        return n+1;
    }
};
