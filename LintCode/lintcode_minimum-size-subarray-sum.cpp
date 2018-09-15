/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        int ans = 0;
        if(!nums.size())
            return ans;
        int sum = 0, j = 0, n = nums.size();
        bool isfind = false;
        ans = n;
        for(int i = 0; i < n; ++ i){
            sum += nums[i];
            if(sum >= s){
                isfind = true;
                while(j <= i && sum >= s){
                    ans = min(ans, i - j + 1);
                    sum -= nums[j];
                    ++ j;
                }
            }
        }
        return isfind?ans:0;
    }
};
