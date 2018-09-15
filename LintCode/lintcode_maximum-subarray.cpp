/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int sum = nums[0], n = nums.size();
    	int ans = nums[0];
    	for(int i = 1; i < n; ++ i){
        	if(sum < 0)
        		sum = nums[i];
        	else
        		sum += nums[i];
        	ans = max(ans, sum);
        }
        return ans;
    }
};

