/*
*
* Tag: DFS + Bit Manipulation
* Time: O(2^n)
* Space: O(n) ?
*/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        int n = nums.size(), mask = 0;
        long long sum = 0, tot = 0, len = 0;
        vector<int> ans, res(4, 0);
        for(int i = 0; i < n; ++ i){
            sum += nums[i];
        }
        if(sum%4 != 0)
            return false;
        tot = sum;
        len = sum/4;
        for(int i = 0; i < n; ++ i){
            if(nums[i] > len)
                return false;
        }
        sort(nums.begin(), nums.end());
        tot = ((1<<n)-1);
        calSideSet(ans, len, nums, 0, n, mask, 0);
        if(ans.size() < 4)
            return false;
        for(int i = 0; i < ans.size() - 3; ++ i){
            res[0] = ans[i];
            for(int j = i + 1; j < ans.size() - 2; ++ j){
                if(res[0]&ans[j])
                    continue;
                res[1] = res[0]|ans[j];
                for(int k = j + 1; k < ans.size() - 1; ++ k){
                    if(res[1]&ans[k])
                        continue;
                    res[2] = res[1]|ans[k];
                    for(int l = k + 1; l < ans.size(); ++ l){
                        if(res[2]&ans[l])
                            continue;
                        res[3] = res[2]|ans[l];
                        if(res[3] == tot)
                            return true;
                    }
                }
            }
        }
        return false;
    }
private:
    void calSideSet(vector<int> &ans, int len, vector<int> &nums, int dep, int n, int mask, int sum){
        if(sum >= len || dep >= n){
            if(sum == len){
                ans.push_back(mask);
            }
            return ;
        }
        calSideSet(ans, len, nums, dep + 1, n, (mask|(1<<dep)), sum + nums[dep]);
        calSideSet(ans, len, nums, dep + 1, n, mask, sum);
    }
};
