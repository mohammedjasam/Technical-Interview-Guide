/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int ans = 0, count = 0;
        for(int num : nums){
            if(count == 0){
                ++ count;
                ans = num;
            } else if(ans != num) {
                -- count;
            } else {
                ++ count;
            }
        }
        
        return ans;
    }
};
