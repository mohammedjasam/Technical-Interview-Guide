/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        if(nums.size() == 0)
            return res;
        int maxnum = 0, mask = 1;
        for(int i = 0; i < nums.size(); ++ i)
            maxnum = max(maxnum, nums[i]);
        while(mask <= maxnum){
            res += getHammingDistPair(nums, mask);
            mask <<= 1;
        }
        return res;
    }
private:
    inline int getHammingDistPair(vector<int>& nums, int mask){
        int cnt[2] = {0};
        for(int i = 0; i < nums.size(); ++ i){
            ++ cnt[((mask&nums[i]) == 0?0:1)];
        }
        return cnt[0]*cnt[1];
    }
};
