/*
*
* Tag: Data Structure (Hash Table)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums: the arrays
     * @param k: the distance of the same number
     * @return: the ans of this question
     */
    string sameNumber(vector<int> &nums, int k) {
        if(nums.size() < 2)
            return "NO";
            
        unordered_map<int,int> numToLastIndexInArray;
        
        for (int i = 0; i < nums.size(); ++ i) {
            int num = nums[i];
            if(numToLastIndexInArray.count(num) > 0) {
                int dist = i - numToLastIndexInArray[num];
                if(dist < k) {
                    return "YES";
                }
            }
            numToLastIndexInArray[num] = i;
        }
        
        return "NO";
    }
};
