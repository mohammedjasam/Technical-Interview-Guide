/*
*
* Tag: DP + Binary Search + Stack
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        if(nums.size() < 2)
            return nums.size();
        vector<int> stk(nums.size() + 1);
        for(int i = 0; i < nums.size(); ++ i){
            binarySearchToUpdateStack(ans, nums[i], stk);
        }
        return ans;
    }
private:
    void binarySearchToUpdateStack(int &ans, int val, vector<int> &stk){
        if(ans == 0 || val > stk[ans - 1]){
            stk[ans ++] = val;
            return ;
        }
        if(val <= stk[0]){
            stk[0] = val;
            return ;
        }
        
        int l = 0, r = ans - 1, id;
        while(l < r){
            int mid = (l + r)>>1;
            if(stk[mid] == val)
                return;
            else if(stk[mid] < val){
                id = mid;
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        stk[l] = val;
    }
};
