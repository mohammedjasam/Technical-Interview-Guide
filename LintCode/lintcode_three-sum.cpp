/*
*
* Tag: Brute Force + Sort
* Time: O(n^2)
* Space: O(1)
*/
class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > ans;
		if(nums.size() == 0)
			return ans;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for(int i = 0; i < n; ++ i){
		    if(i && nums[i] == nums[i-1]) continue;
			int l = i + 1, r = n - 1;
			while(l < r){
            	if(nums[i] + nums[l] + nums[r] == 0){
                	vector<int> tmp(3);
                	tmp[0] = nums[i];
                	tmp[1] = nums[l];   
                	tmp[2] = nums[r];
                	ans.push_back(tmp);
                	while(l < r && nums[l] == nums[l + 1])
		                l ++;
                    l ++;
                    while(l < r && nums[r] == nums[r - 1])
		                r --;
	                r --;
                }else if(nums[i] + nums[l] + nums[r] > 0){
                	r --;
                }else{
                	l ++;
                }
            }
        }
        return ans;
    }
};

