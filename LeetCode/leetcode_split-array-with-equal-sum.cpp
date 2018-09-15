/*
*
* Tag: Data Structure
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if(nums.size() < 7)
            return false;
        int n = nums.size();
        vector<int> sum(n + 1);
        unordered_map<int,vector<int>> dict;
        sum[n] = 0;
        dict.clear();
        for(int i = n - 1; i >= 0; -- i){
            sum[i] = sum[i + 1] + nums[i];
            dict[sum[i]].push_back(i);
        }
        int presum = 0;
        for(int i = 0; i < n - 5; ++ i){
            presum += nums[i];
            if(dict.find(presum) != dict.end()){
                for(int j = 0; j < dict[presum].size(); ++ j){
                    if(dict[presum][j] - i < 4)
                        break;
                    if(check(presum, i + 2, dict[presum][j] - 1, sum, nums))
                        return true;
                }
            }
        }
        return false;
    }
private:
    bool check(int chksum, int sta, int bnd, vector<int> &sum, vector<int>& nums){
        int fsum = 0, tmp = 0;
        for(int i = sta; i < bnd - 2; ++ i){
            fsum += nums[i];
            tmp = sum[i + 2] - sum[bnd];
            if(fsum == chksum && fsum == tmp)
                return true;
        }
        return false;
    }
};
