/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int ans = 0;
        if(nums.size() == 0)
            return ans;
        
        pair<int,int> lastOnesBound(-3, -3);
        for(int fastPointer = 0; fastPointer < nums.size(); ++ fastPointer){
            int numOfOnes = 0;
            while(fastPointer < nums.size() && nums[fastPointer] == 1) {
                ++ numOfOnes;
                ++ fastPointer;
            }
            ans = max(ans, numOfOnes);
            
            if(fastPointer < nums.size() || numOfOnes < fastPointer)
                ans = max(ans, numOfOnes + 1);
            
            if(numOfOnes > 0) {
                pair<int,int> curOnesBound(fastPointer - numOfOnes, fastPointer - 1);
                if(curOnesBound.first - lastOnesBound.second <= 2) {
                    ans = max(ans, numOfOnes + lastOnesBound.second - lastOnesBound.first + 2);
                }
                
                lastOnesBound = curOnesBound;
            }
            
        }  
        
        return ans;
    }
};
