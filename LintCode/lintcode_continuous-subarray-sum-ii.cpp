/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        vector<int> ans(2);
        if(!A.size())
            return ans;
        
        int start = 0, end = 0, maxval = INT_MIN;
        int sum = 0, n = A.size();
        for(int i = 0; i < n; ++ i){
            sum += A[i];
            if(sum >= 0){
                if(sum > maxval){
                    end = i;
                    maxval = sum;
                    ans[0] = start;
                    ans[1] = end;
                }
            }else{
                if(sum > maxval){
                    maxval = sum;
                    end = i;
                    ans[0] = start;
                    ans[1] = end;
                }
                sum = 0;
                start = i + 1;
            }
        }
        
        vector<int> dp_start(n), dp_end(n);
        vector<int> idx_start(n), idx_end(n);
        sum = A[0];
        dp_start[0] = sum;
        idx_start[0] = 0;
        for(int i = 1; i < n; ++ i){
            sum += A[i];
            if(sum > dp_start[i - 1]){
                dp_start[i] = sum;
                idx_start[i] = i;
            }else{
                dp_start[i] = dp_start[i - 1];
                idx_start[i] = idx_start[i - 1];
            }
        }
        sum = A[n - 1];
        dp_end[n - 1] = sum;
        idx_end[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; -- i){
            sum += A[i];
            if(sum > dp_end[i + 1]){
                dp_end[i] = sum;
                idx_end[i] = i;
            }else{
                dp_end[i] = dp_end[i + 1];
                idx_end[i] = idx_end[i + 1];
            }
        }
        for(int i = 0; i < n - 1; ++ i){
            int tmpsum = dp_start[i] + dp_end[i + 1];
            if(tmpsum > maxval){
                maxval = tmpsum;
                ans[0] = idx_end[i + 1];
                ans[1] = idx_start[i];
            }
        }
        return ans;
    }
};
