/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        if(nums.size() <= 1)
            return ;
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        int sta = tmp.size()/2, n = tmp.size();
        if(n%2)
            ++ sta;
        int j = n - 1;
        for(int i = 1; j >= sta; i += 2, -- j){
            nums[i] = tmp[j];
        }
        j = sta - 1;
        for(int i = 0; j >= 0; i += 2, -- j){
            nums[i] = tmp[j];
        }
    }
};
