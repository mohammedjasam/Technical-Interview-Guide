/*
* TODO
* Tag: Bit Manipulation
* Time : O(n)
* Memory : O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        if(nums.size() <= 2)
            return nums;
        int xorval = nums[0];
        for(int i = 1; i < nums.size(); ++ i){
            xorval ^= nums[i];
        }
        
        int idx = find(xorval);
        int first = 0, second = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if((nums[i]>>idx)&1){
                first ^= nums[i];
            }else{
                second ^= nums[i];
            }
        }
        ans[0] = first;
        ans[1] = second;
        return ans;
    }
    
private:   
    int find(int val){
        int res = (int)log2(val&-val);
        return res;
    }
    
};
