/*
*
* Tag: Sort
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        if(!A.size())
            return ;
        for(int i = 0; i < A.size(); ++ i){
            int minval = A[i], id = i;
            for(int j = i + 1; j < A.size(); ++ j){
                if(minval > A[j]){
                    minval = A[j];
                    id = j;
                }
            }
            swap(A[i], A[id]);
        }
        return ;
    }
};
