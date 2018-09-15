/*
*
* Tag: DFS
* Time: ?
* Space: ?
*/
class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &num) {
        // write your code here
        if(num.size() == 0)
            return ;
        if(!next_permutation(num.begin(), num.end()))
            sort(num.begin(), num.end());
    }
};
