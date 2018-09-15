/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        if(A.size() == 0)
            return true;
        int bnd = 0, idx = 0;
        int n = A.size();
        for(;;){
            bnd = idx + A[idx];
            if(bnd >= n)
                break;
            int maxjmp = -1;
            for(int j = idx + 1; j <= bnd; ++ j){
                if(j + A[j] > maxjmp){
                    maxjmp = j + A[j];
                    idx = j;
                }
            }
            if(bnd >= maxjmp)
                return false;
        }
        return true;
    }
};
