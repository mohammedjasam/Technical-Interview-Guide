/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        if(nums.size() == 0 || k < 0)
            return ans;
        unordered_map<int,int> dict;
        for(int i = 0; i < nums.size(); ++ i)
            ++ dict[nums[i]];
        unordered_map<int,int>::iterator it = dict.begin();
        for(; it != dict.end(); ++ it){
            if(dict.find(it->first - k) != dict.end()){
                if(k != 0)
                    ++ ans;
                else if(it->second > 1)
                    ++ ans;
            }
        }
        return ans;
    }
};
