/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        bool allpos = true, allneg = true;
        for(int i = 0; i < nums.size();  ++ i){
            if(nums[i] < 0){
                allpos = false;
                break;
            }
        }
      for(int i = 0; i < nums.size();  ++ i){
            if(nums[i] >= 0){
                allneg = false;
                break;
            }
        }
        int ans;
        if(!allpos && !allneg){
            vector<vector<int> > HtT(2, vector<int>(nums.size())), TtH(2, vector<int>(nums.size()));
            int maxval = INT_MIN, minval = INT_MAX;
            int maxsum = 0, minsum = 0;
            HtT[0][0] = HtT[1][0] = nums[0];
            maxsum = nums[0];
            minsum = nums[0];
            for(int i = 1; i < nums.size(); ++ i){
                if(maxsum + nums[i] < nums[i]){
                    maxval = max(maxval, nums[i]);
                    maxsum = nums[i];
                }else{
                    maxval = max(maxval, maxsum + nums[i]);
                    maxsum += nums[i];
                }
                if(minsum + nums[i] > nums[i]){
                    minval = min(minval, nums[i]);
                    minsum = nums[i];
                }else{
                    minval = min(minval, minsum + nums[i]);
                    minsum += nums[i];
                }
                HtT[0][i] = maxval;
                HtT[1][i] = minval;
            }
            
            maxval = INT_MIN, minval = INT_MAX;
            maxsum = nums[nums.size() - 1];
            minsum = nums[nums.size() - 1];
            TtH[0][nums.size() - 1] = TtH[1][nums.size() - 1] = nums[nums.size() - 1];
            for(int i = nums.size() - 2; i >= 0; -- i){
                if(maxsum + nums[i] < nums[i]){
                    maxval = max(maxval, nums[i]);
                    maxsum = nums[i];
                }else{
                    maxval = max(maxval, maxsum + nums[i]);
                    maxsum += nums[i];
                }
                if(minsum + nums[i] > nums[i]){
                    minval = min(minval, nums[i]);
                    minsum = nums[i];
                }else{
                    minval = min(minval, minsum + nums[i]);
                    minsum += nums[i];
                }
                TtH[0][i] = maxval;
                TtH[1][i] = minval;
            }
            
            ans = INT_MIN;
            for(int i = 0; i < nums.size() - 1; ++ i){
                int tmpval = HtT[0][i] - TtH[1][i + 1];
                if(tmpval < 0)
                    tmpval = -tmpval;
                ans = max(tmpval, ans);
                tmpval = TtH[0][i + 1] - HtT[1][i];
                if(tmpval < 0)
                    tmpval = -tmpval;
                ans = max(tmpval, ans);
                tmpval = HtT[0][i] - TtH[0][i + 1];
                if(tmpval < 0)
                    tmpval = -tmpval;
                ans = max(tmpval, ans);
                tmpval = TtH[1][i + 1] - HtT[1][i];
                if(tmpval < 0)
                    tmpval = -tmpval;
                ans = max(tmpval, ans);
            }
        }
        else if(allpos && !allneg){
            int minpos = INT_MAX, sumpos = 0;
            for(int i = 0; i < nums.size(); ++ i ){
                minpos = min(minpos, nums[i]);
                sumpos += nums[i];
            }
            ans = sumpos - 2*minpos;
        }else if(!allpos && allneg){
            int maxneg = INT_MIN, sumneg = 0;
            for(int i = 0; i < nums.size(); ++ i){
                maxneg = max(maxneg, nums[i]);
                sumneg += nums[i];
            }
            ans = sumneg - 2*maxneg;
        }
        if(ans < 0)
            ans = -ans;
        return ans;
    }
};

