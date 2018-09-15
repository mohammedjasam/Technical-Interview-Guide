/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    Solution(vector<int> nums) {
        srand (time(NULL));
        arr.resize(nums.size());
        orgarr.resize(nums.size());
        for(int i = 0; i < nums.size(); ++ i)
            orgarr[i] = arr[i] = nums[i];
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        if(arr.size() == 0)
            return arr;
        for(int i = 0; i < arr.size(); ++ i)
            arr[i] = orgarr[i];
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(arr.size() == 0)
            return arr;
        for(int i = 0; i < arr.size() - 1; ++ i)
            swap(arr[i], arr[rand()%(arr.size() - i) + i]);
        return arr;
    }
private:
    vector<int> arr, orgarr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
