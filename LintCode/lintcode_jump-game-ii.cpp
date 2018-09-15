/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        if(A.size() == 0)
            return 0;
        int bnd = 0, idx = 0, ans = 0;
        int n = A.size();
        for(;;){
            bnd = idx + A[idx];
            ++ ans;
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
                return -1;
        }
        return ans;
    }
};
