/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size() == 0){
            return true;
        }
        
        unordered_map<int,int> frequencyOfNum, requiredNum;
        for(int num : nums){
            ++ frequencyOfNum[num];
        }
        
        for(int num : nums){
            if(frequencyOfNum[num] == 0){
                continue;
            }
            
            if(requiredNum[num] > 0){
                -- requiredNum[num];
                ++ requiredNum[num + 1];
            } else if(frequencyOfNum[num + 1] > 0 && frequencyOfNum[num + 2] > 0){
                -- frequencyOfNum[num + 1];
                -- frequencyOfNum[num + 2];
                ++ requiredNum[num + 3];
            } else {
                return false;
            }
            
            -- frequencyOfNum[num];
        }
        
        return true;
    }
};
