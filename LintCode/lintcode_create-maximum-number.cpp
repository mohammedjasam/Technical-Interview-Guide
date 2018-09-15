/*
*
* Tag: Greedy
* Time: O(k^2)
* Space: O(k)
*/
class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans(k, 0);
		if(!k)
		    return ans;
		string res = "";
		for(int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size());  ++ i){
		    string lnum = getLargestSubstr(nums1, i);
		    string rnum = getLargestSubstr(nums2, k - i);
		    string tmp = combineStr(lnum, rnum, k);
		    res = max(res, tmp);
		}
		for(int i = 0; i < k; ++ i)
		    ans[i] = (int)(res[i] - '0');
		return ans;
	}
private:
    string getLargestSubstr(vector<int>& nums, int k){
        string res(k, '0');
        if(!k)
            return "";
        int len = 0, n = nums.size();
        for(int i = 0; i < n; ++ i){
            while(len && len + n - i > k && (char)(nums[i] + '0') > res[len - 1])
                -- len;
            if(len < k)
                res[len ++] = (char)(nums[i] + '0');
        }
        return res;
    }
 
    string combineStr(string &lnum, string &rnum, int k){
        string res(k, '0');
        int i = 0, j = 0, l = 0;
        while(i < lnum.size() && j < rnum.size()){
            if(lnum[i] > rnum[j]){
                res[l ++] = lnum[i ++];
            }else if(lnum[i] < rnum[j]){
                res[l ++] = rnum[j ++];
            }else{
                string lsubstr = lnum.substr(i + 1), rsubstr = rnum.substr(j + 1);
                if(lsubstr >= rsubstr)
                    res[l ++] = lnum[i ++];
                else
                    res[l ++] = rnum[j ++]; 
            }
        }
        while(i < lnum.size()) res[l ++] = lnum[i ++];
        while(j < rnum.size()) res[l ++] = rnum[j ++];
        return res;
    }
};
