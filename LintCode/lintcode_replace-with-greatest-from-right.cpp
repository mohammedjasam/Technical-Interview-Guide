/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /*
     * @param : An array of integers.
     * @return: nothing
     */
    void arrayReplaceWithGreatestFromRight(vector<int> &nums) {
        if(nums.size() == 0)
            return ;
            
        int top = 0;
        int n = nums.size();
        vector<pair<int,int>> stackOfNextGreatestNumbers(n + 1);
        for(int i = 0; i < n; ++ i){
            while(top > 0 && getTopElementOfStack(stackOfNextGreatestNumbers, top) < nums[i]){
                -- top;
            }
            
            pushElementToStack(make_pair(nums[i], i), stackOfNextGreatestNumbers, top);
        }
        
        pushElementToStack(make_pair(-1, n), stackOfNextGreatestNumbers, top);
        
        for(int i = 0, j = 0; j < top; ) {
            if(canReplaceElementOfCurrentIndexWithStackElement(i, stackOfNextGreatestNumbers, j)){
                nums[i ++] = stackOfNextGreatestNumbers[j].first;
            } else
                ++ j;
        }
        
        return ;
    }
private:
    int getTopElementOfStack(vector<pair<int,int>> &stackOfNextGreatestNumbers, int top){
        return stackOfNextGreatestNumbers[top - 1].first;
    }
    
    void pushElementToStack(pair<int,int> newStackElement, vector<pair<int,int>> &stackOfNextGreatestNumbers, int &top) {
        stackOfNextGreatestNumbers[top ++] = newStackElement;
    }
    
    bool canReplaceElementOfCurrentIndexWithStackElement(int curIdx, vector<pair<int,int>> &stackOfNextGreatestNumbers, int stackIdx){
        return curIdx < stackOfNextGreatestNumbers[stackIdx].second;
    }
};
