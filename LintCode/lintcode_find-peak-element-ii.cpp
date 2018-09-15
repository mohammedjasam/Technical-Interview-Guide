/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        vector<int> ans(2);
        if(!A.size())
            return ans;
        int n = A.size(), m = A[0].size(), r, c;
        if(n == 1){
            r = 0;
            for(int i = 1; i < m - 1; ++ i){
                if(A[0][i] > A[0][i - 1] && A[0][i] > A[0][i + 1]){
                    c = i;
                    break;
                }
            }
        }else if(m == 1){
            c = 0;
            for(int i = 1; i < n - 1; ++ i){
                if(A[i][0] > A[i - 1][0] && A[i][0] > A[i + 1][0]){
                    r = i;
                    break;
                }
            }
        }else{
            r = 1, c = 1;
            for(; r < n - 1 && c < m - 1;){
                if(A[r][c] > A[r][c + 1] && A[r][c] > A[r + 1][c])
                    break;
                if(A[r][c + 1] > A[r + 1][c])
                    ++ c;
                else
                    ++ r;
            }
        }
        ans[0] = r;
        ans[1] = c;
        return ans;
    }
};

