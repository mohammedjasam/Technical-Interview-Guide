/*
*
* Tag: Hash (Data Structure)
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return false;
        
        unordered_map<int,int> dict;
        for(int i = 0; i < nums.size(); ++ i){
            if(dict.find(nums[i]) == dict.end()){
                dict[nums[i]] = i;
            }else{
                if(abs(i - dict[nums[i]]) <= k)
                    return true;
                dict[nums[i]] = i;
            }
        }
        
        return false;
    }
};
