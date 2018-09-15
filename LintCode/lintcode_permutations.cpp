/*
*
* Tag: Backtracking
* Time: O(n!)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > ans;
        if(nums.size() == 0)
            return ans;
        sort(nums.begin(), nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

