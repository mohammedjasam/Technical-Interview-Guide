/*
*
* Tag: Brute Force
* Time: O(n) 
* Space: O(k)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> ans;
        int maxval = INT_MIN;
        if(!nums.size() || !k)
            return ans;
        if(nums.size() < k){
            ans.resize(1);
            maxval = INT_MIN;
            for(int i = 0; i < nums.size(); ++ i)
                maxval = max(maxval, nums[i]);
            ans[0] = maxval;
            return ans;
        }
        int i = 0, cnt = 0;
        int n = nums.size();
        vector<int> windows(k);
        for(; i < k; ++ i){
            if(nums[i] == maxval)
                ++ cnt;
            else if(nums[i] > maxval){
                maxval = nums[i];
                cnt = 1;
            }
            windows[i%k] = nums[i];
        }
        ans.push_back(maxval);
        for(; i < n; ++ i){
            int id = i%k;
            if(windows[id] == maxval){
                if(nums[i] > maxval){
                    maxval = nums[i];
                    cnt = 1;
                    ans.push_back(maxval);
                }else{
                    -- cnt;
                    if(cnt){
                        ans.push_back(maxval);
                    }else{
                        windows[id] = nums[i];
                        maxval = windows[0];
                        cnt = 1;
                        for(int j = 1; j < k; ++ j){
                            if(windows[j] == maxval)
                                ++ cnt;
                            else if(windows[j] > maxval){
                                maxval = windows[j];
                                cnt = 1;
                            }
                        }
                        ans.push_back(maxval);
                    }
                }
                windows[id] = nums[i];
            }else{ 
                if(nums[i] > maxval){
                    maxval = nums[i];
                    cnt = 1;
                }else{
                    if(k == 1){
                        maxval = nums[i];
                        cnt = 1;
                    }
                }
                ans.push_back(maxval);
                windows[id] = nums[i];
            }
        }
        return ans;
    }
};

