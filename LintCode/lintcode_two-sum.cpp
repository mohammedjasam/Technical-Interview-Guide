/*
*
* Tag: Brute Force
* Time: O(n^2) (Can be O(n))
* Space: O(1) (Can be O(n))
*/
class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> res(2);
        if(nums.size() == 0)
            return nums;
        //sort(nums.begin(), nums.end());
        int n = nums.size();
        bool isfind = false;
    //    int l = 0, r = nums.size() - 1;
        for(int i = 0; i < n; ++ i){
            for(int j = i + 1; j < n; ++ j){
                if(nums[i] + nums[j] == target){
                    res[0] = i + 1;
                    res[1] = j + 1;
                    isfind = true;
                    break;
                }
            }
            if(isfind)
                break;
        }
        
        return res;
    }
};
