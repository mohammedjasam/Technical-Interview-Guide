/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param n: 
     * @param nums: 
     * @return: return the sum of maximum OR sum, minimum OR sum, maximum AND sum, minimum AND sum.
     */
    long long getSum(int n, vector<int> &nums) {
        if(n == 0)
            return 0;
        long long minAndSum = nums[0], maxAndSum = nums[0], minORSum = nums[0], maxORSum = nums[0];
        for(int i = 1; i < n; ++ i){
            minAndSum &= nums[i];
            maxAndSum = max(maxAndSum, (long long)nums[i]);
            minORSum = min(minORSum, (long long)nums[i]);
            maxORSum |= nums[i];
        }
        
        return minAndSum + maxAndSum + minORSum + maxORSum;
    }
};
