/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(!nums.size()){
            return ans;
        }
        
        if(nums.size() == 1){
            string res = to_string(cur);
            ans.push_back(res);
        }
        
        int n = nums.size();
        int cur = nums[0];
        for(int i = 1; i < n; ++ i){
            if(nums[i] == cur + 1){
                int prev = cur;
                while(i < n && nums[i] == prev + 1){
                    prev = nums[i];
                    ++ i;
                }
                string first = to_string(cur), second = to_string(prev);
                string res=first+"->"+second;
                ans.push_back(res);
                if(i == n)
                    break;
                cur = nums[i];
            }else{
                string res = to_string(cur);
                ans.push_back(res);
                cur = nums[i];
            }
            if(i == n - 1){
                string res = to_string(cur);
                ans.push_back(res);
            }
        }
        
        return ans;
    }
};
