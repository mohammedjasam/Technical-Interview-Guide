/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0 || k == 0){
            return ans;
        }
        
        vector<int> kElementsSum(nums.size() - k + 1);
        int sum = 0;
        for(int i = 0; i < nums.size(); ++ i){
            sum += nums[i];
            if(i >= k){
                sum -= nums[i - k];
            }
            if(i >= k - 1){
                kElementsSum[i - k + 1] = sum;
            }
        }
        
        vector<int> leftIndexOfLargestSum(kElementsSum.size());
        int best = 0;
        for(int i = 0; i < kElementsSum.size(); ++ i){
            if(kElementsSum[i] > kElementsSum[best]){
                best = i;
            }
            
            leftIndexOfLargestSum[i] = best;
        }
        
        vector<int> rightIndexOfLargestSum(kElementsSum.size());
        best = kElementsSum.size() - 1;
        for(int i = kElementsSum.size() - 1; i >= 0; -- i){
            if(kElementsSum[i] >= kElementsSum[best]){
                best = i;
            }
            
            rightIndexOfLargestSum[i] = best;
        }
        
        ans.resize(3);
        fill(ans.begin(), ans.end(), -1);
        for(int j = k; j < kElementsSum.size() - k; ++ j){
            int indexOfFirstSubarray = leftIndexOfLargestSum[j - k], indexOfSecondSubarray = rightIndexOfLargestSum[j + k];
            if(ans[0] == -1 || (kElementsSum[indexOfFirstSubarray] + kElementsSum[j] + kElementsSum[indexOfSecondSubarray] > kElementsSum[ans[0]] + kElementsSum[ans[1]] + kElementsSum[ans[2]])){
                ans[0] = indexOfFirstSubarray;
                ans[1] = j;
                ans[2] = indexOfSecondSubarray;
            }
        }
        
        return ans;
    }
};
