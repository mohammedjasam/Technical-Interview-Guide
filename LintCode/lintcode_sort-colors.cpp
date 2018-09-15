/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int red = 0, white = 0, blue = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(nums[i] == 0)
                ++ red;
            else if(nums[i] == 1)
                ++ white;
            else
                ++ blue;
        }
        for(int i = 0; i < nums.size(); ++ i){
            if(i < red)
                nums[i] = 0;
            else if(i < white + red)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};
