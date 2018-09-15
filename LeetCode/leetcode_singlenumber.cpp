/*
*
* Tag: Bit Manipulation
* Time : O(n)
* Memory : O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            ans ^= num;
        }
        
        return ans;
    }
};

