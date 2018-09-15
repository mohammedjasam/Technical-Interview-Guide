/*
*
* Tag: Binary Search
* Time: O(log(maxnum[i] - minnum[i])*n)
* Space: O(1)
*/
class Solution {
private:
    const double eps = 1e-6;
public:
    /**
     * @param nums an array with positive and negative numbers
     * @param k an integer
     * @return the maximum average
     */
    double maxAverage(vector<int>& nums, int k) {
        // Write your code here
        double l = INT_MAX, r = INT_MIN, mid = 0, min_presum = 0;
        bool check = false;
        vector<double> sum(nums.size() + 1);
        for(int i = 0; i < nums.size(); ++ i){
            l = min(l, (double)nums[i]);
            r = max(r, (double)nums[i]);
        }
        sum[0] = 0;
        while(r - l >= eps){
            mid = (r + l)/2.0;
            min_presum = 0;
            check = false;
            for(int i = 1; i <= nums.size(); ++ i){
                sum[i] = sum[i - 1] + nums[i - 1] - mid;
                if(i >= k && sum[i] - min_presum >= 0){
                    check = true;
                    break;
                }
                if(i >= k)
                    min_presum = min(min_presum, sum[i - k + 1]);
            }
            if(check){
                l = mid;
            }else
                r = mid;
        }
        return l;
    }
};
