/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
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
        return ans;
    }
};
