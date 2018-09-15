/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your 
        vector<int> ans;
        if(nums.size() == 0)
            return ans;
        int n = nums.size();
        unordered_map<int,int> dic_idx;
        int sum = 0;
        for(int i = 0; i < n; ++ i){
            if(nums[i] == 0){
                ans.resize(2);
                ans[0] = ans[i] = i;
                break;
            }
            sum += nums[i];
            if(sum == 0){
                ans.resize(2);
                ans[0] = 0;
                ans[1] = i;
                break;
            }
            if(dic_idx.find(sum) != dic_idx.end()){
                ans.resize(2);
                ans[0] = dic_idx[sum] + 1;
                ans[1] = i;
                break;
            }else
                dic_idx[sum] = i;
        }
        return ans;
    }
};
