/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int ans = 0;
        int idx = 0;
        for(int i = 0; i < A.size(); ++ i){
            if(A[i] == elem){
                ++ ans;
            }else{
                A[idx] = A[i];
                ++ idx;
            }
        }
        return A.size() - ans;
    }
};
