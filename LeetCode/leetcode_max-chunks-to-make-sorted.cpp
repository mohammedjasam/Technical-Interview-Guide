/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() < 2) {
            return arr.size();
        }
        
        int ans = 0;
        vector<bool> visitedNum(arr.size(), false);
        int minOfCurrentChunk = 0, maxOfCurrentChunk = 0;
        for(int val : arr){
            maxOfCurrentChunk = max(val, maxOfCurrentChunk);
            visitedNum[val] = true;
            if(isValidChunk(minOfCurrentChunk, maxOfCurrentChunk, visitedNum)) {
                ++ ans;
                minOfCurrentChunk = maxOfCurrentChunk + 1;
                maxOfCurrentChunk = 0;
            }
        }
        
        return ans;
    }
    
private:
    bool isValidChunk(int minOfCurrentChunk, int maxOfCurrentChunk, vector<bool> &visitedNum){
        for(int i = minOfCurrentChunk; i <= maxOfCurrentChunk; ++ i){
            if(!visitedNum[i]){
                return false;
            }
        }
        
        return true;
    }
};

/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size() < 2) {
            return arr.size();
        }
        
        int ans = 0;
        int maxVal = 0;
        for(int i = 0; i < arr.size(); ++ i){
            maxVal = max(maxVal, arr[i]);
            if(maxVal == i){
                ++ ans;
            }
        }
        
        return ans;
    }
};
