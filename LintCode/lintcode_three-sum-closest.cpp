/*
*
* Tag: Brute Force + Sort
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int ans = INT_MAX, n = nums.size(), origin_dif = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; ++ i){
            int j = i + 1, k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int dif = sum - target, tmpdif;
                tmpdif = dif;
                if(dif<0)
                    dif = -dif;
                if(dif < origin_dif){
                    ans = sum;
                    origin_dif = dif;
                    if(tmpdif < 0)
                        j ++;
                    else
                        k --;
                }else{
                    if(tmpdif < 0)
                        j ++;
                    else
                        k --;
                }
            }
        }
        return ans;
    }
};

