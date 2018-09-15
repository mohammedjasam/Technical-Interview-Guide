/*
*
* Tag: Data Structure (Hash)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /*
     * @param : the given array
     * @param : the window size
     * @return: the sum of the count of unique elements in each window
     */
    int slidingWindowUniqueElementsSum(vector<int> nums, int k) {
        int sum = 0;
        if(nums.size() == 0 || k == 0)
            return sum;
        int numOfUniqElements = 0;
        unordered_map<int,int> elementsCount;
        
        int idx = 0;
        for(; idx < min(k, (int)nums.size()); ++ idx) {
            updateNumOfUniqElementsWhenAppendElementToWindow(numOfUniqElements, elementsCount, nums[idx]);
        }
        sum += numOfUniqElements;
        
        for(; idx < nums.size(); ++ idx){
            updateNumOfUniqElementsWhenPopElementFromWindow(numOfUniqElements, elementsCount, nums[idx - k]);
            updateNumOfUniqElementsWhenAppendElementToWindow(numOfUniqElements, elementsCount, nums[idx]);
            
            sum += numOfUniqElements;
        }
        
        return sum;
    }
private:
    void updateNumOfUniqElementsWhenPopElementFromWindow(int &numOfUniqElements, unordered_map<int,int> &elementsCount, int targetElement) {
        -- elementsCount[targetElement];
        if(elementsCount[targetElement] == 1)
            ++ numOfUniqElements;
        else if(elementsCount[targetElement] == 0)
            -- numOfUniqElements;
    }
    
    void updateNumOfUniqElementsWhenAppendElementToWindow(int &numOfUniqElements, unordered_map<int,int> &elementsCount, int targetElement) {
        ++ elementsCount[targetElement];
        if(elementsCount[targetElement] == 1)
            ++ numOfUniqElements;
        else if(elementsCount[targetElement] == 2)
            -- numOfUniqElements;
    }
};
