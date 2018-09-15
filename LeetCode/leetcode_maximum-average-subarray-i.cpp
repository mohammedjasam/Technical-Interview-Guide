/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(i >= k){
                sum -= nums[i - k];
            }
            
            sum += nums[i];
            if(i >= k - 1){
                maxSum = max(maxSum, sum);
            }
        }
        
        return (double)maxSum/k;
    }
};
