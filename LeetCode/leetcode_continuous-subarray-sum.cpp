/*
*
* Tag: DP
* Time: O(nk)
* Space: O(k)
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2)
            return false;
        int n = nums.size();
        if(k == 0){
            int cnt_zero = 0;
            for(int i = 0; i < n; ++ i){
                if(nums[i] == 0){
                    ++ cnt_zero;
                } else {
                    cnt_zero = 0;
                }
                if(cnt_zero >= 2)
                    return true;
            }
            return false;
        }
        unordered_set<int> predp, curdp;
        unordered_set<int>::iterator it;
        predp.clear();
        predp.insert(nums[0]%k);
        int u = 0;
        for(int i = 1; i < n; ++ i){
            u = nums[i]%k;
            curdp.clear();
            for(it = predp.begin(); it != predp.end(); ++ it){
                curdp.insert( (*it + u)%k );
            }
            if(curdp.find(0) != curdp.end())
                return true;
            predp = curdp;
            predp.insert(u);
        }
        return false;
    }
};
