/*
*
* Tag: Data Structure (Map)
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        if(arr.size() == 0){
            return ans;
        }
        
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());
        
        map<int,int> frequencyOfNum;
        int nonZeroFrequencyCount = 0;
        for(int i = 0; i < arr.size(); ++ i){
            int numOfArr = arr[i], numOfSortedArr = sortedArr[i];
            
            if(frequencyOfNum.count(numOfArr) == 0){
                frequencyOfNum[numOfArr] = 0;
            }
            ++ frequencyOfNum[numOfArr];
            
            if(frequencyOfNum[numOfArr] == 0){
                -- nonZeroFrequencyCount;
            }
            if(frequencyOfNum[numOfArr] == 1){
                ++ nonZeroFrequencyCount;
            }
            
            if(frequencyOfNum.count(numOfSortedArr) == 0){
                frequencyOfNum[numOfSortedArr] = 0;
            }
            -- frequencyOfNum[numOfSortedArr];
            
            if(frequencyOfNum[numOfSortedArr] == 0){
                -- nonZeroFrequencyCount;
            }
            if(frequencyOfNum[numOfSortedArr] == -1){
                ++ nonZeroFrequencyCount;
            }
            
            if(nonZeroFrequencyCount == 0){
                ++ ans;
            }
        }
        
        return ans;
    }
    
};


/*
*
* Tag: Data Structure (Map)
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        if(arr.size() == 0){
            return ans;
        }
        
        map<int,int> numOfFrequency;
        for(int num : arr){
            ++ numOfFrequency[num];
        }
        
        auto itOfMinValueOfChunk = numOfFrequency.begin(), itOfMaxValueOfChunk = numOfFrequency.begin();
        int maxValueOfChunk = itOfMaxValueOfChunk->first;
        unordered_map<int,int> numOfChunkFrequency;
        for(int value : arr){
            if(value > maxValueOfChunk){
                maxValueOfChunk = value;
                itOfMaxValueOfChunk = numOfFrequency.find(maxValueOfChunk);
            }
            
            ++ numOfChunkFrequency[value];
            if(isValidChunk(itOfMinValueOfChunk, itOfMaxValueOfChunk, numOfFrequency, numOfChunkFrequency)){
                ++ ans;
                numOfFrequency[maxValueOfChunk] -= numOfChunkFrequency[maxValueOfChunk];
                
                numOfChunkFrequency.clear();
                if(numOfFrequency[maxValueOfChunk] > 0) {
                    itOfMinValueOfChunk = itOfMaxValueOfChunk;
                } else {
                    ++ itOfMaxValueOfChunk;
                    itOfMinValueOfChunk = itOfMaxValueOfChunk;
                }

                if(itOfMaxValueOfChunk != numOfFrequency.end()){
                    maxValueOfChunk = itOfMaxValueOfChunk->first;
                }
            }
        }
        
        return ans;
    }
    
private:
    bool isValidChunk(auto itOfMinValueOfChunk, auto itOfMaxValueOfChunk, map<int,int> &numOfFrequency, unordered_map<int,int> &numOfChunkFrequency){
        for(auto it = itOfMinValueOfChunk; it != itOfMaxValueOfChunk; ++ it){
            int num = it->first, frequency = it->second;
            if(frequency > numOfChunkFrequency[num]){
                return false;
            }
        }
        
        return true;
    }
    
};
