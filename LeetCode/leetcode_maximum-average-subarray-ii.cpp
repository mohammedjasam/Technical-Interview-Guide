/*
*
* Tag: Binary Search
* Time: O(nlgm) m is the difference between max value and min value of binary search
* Space: O(1)
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = INT_MIN, r = INT_MAX;
        while(l + 0.00001 < r){
            double mid = (l + r)/2;
            if(isLargerThanMaxAverage(nums, k, mid)){
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return l;
    }
    
private:
    bool isLargerThanMaxAverage(vector<int>& nums, int k, double mid){
        double sum = 0, prevSum = 0, minPrevSum = 0;
        for(int i = 0; i < nums.size(); ++ i){
            sum += nums[i] - mid;
            if(i >= k){
                prevSum += nums[i - k] - mid;
                minPrevSum = min(minPrevSum, prevSum);
            }
            
            if(i >= k - 1 && sum > minPrevSum){
                return false;
            }
        }
        
        return true;
    }
};
