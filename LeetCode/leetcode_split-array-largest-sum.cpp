/*
*
* Tag: Binary Search
* Time: O(lg(sum))
* Space: O(1)
*/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long right = 0, left = 0, mid, ans = 0;
        for(int i = 0; i < nums.size(); ++ i){
            left = max(left, (long long)nums[i]);
            right += nums[i];
        }
        ans = right;
        if(m == 1)
            return ans;
        while(left < right){
            if(left == right){
                break;
            }
            mid = left + ((right - left)/2);
            if(check(mid, m, nums)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return (int)left;
    }
private:
    bool check(long long sum, int m, vector<int> &nums){
        long long tmpsum = 0;
        int i = 0, cnt = 1;
        for(; i < nums.size(); ++ i){
            tmpsum += nums[i];
            if(tmpsum > sum){
                tmpsum = nums[i];
                ++ cnt;
            }
        }
        return cnt <= m;
    }
};
