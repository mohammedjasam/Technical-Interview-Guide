/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        // Write your code here
        int ans = 0;
        if(!A.size())
            return ans;
        int sum = 0, n = A.size();
        for(int i = 0; i < n; ++ i){
            sum += A[i];
            if(sum >= start && sum <= end)
                ++ ans;
            A[i] = sum;
        }
        int start_idx = -1, end_idx = 0;
        for(; end_idx < n; ++ end_idx){
            sum = A[end_idx];
            if(sum >= start){
                start_idx = 0;
                while(start_idx < end_idx){
                    int tmp_sum = A[end_idx] - A[start_idx];
                    if(tmp_sum >= start && tmp_sum <= end){
                        ++ ans;
                    }
                    ++ start_idx;
                }
            }
        }
        return ans;
    }
};
