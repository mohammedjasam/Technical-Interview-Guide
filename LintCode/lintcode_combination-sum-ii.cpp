/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> ans;
        if(num.size() == 0)
            return ans;
        sort(num.begin(), num.end());
        int sum = 0;
        for(int i = 0; i < num.size(); ++ i){
            vector<int> tmpans;
            if(sum + num[i] > target)
                break;
            tmpans.push_back(num[i]);
            dfs(tmpans, ans, num, sum + num[i], target, i);
            while(i + 1 < num.size() && num[i] == num[i + 1]) ++ i;
        }
        return ans;
    }
    
    void dfs(vector<int> &tmpans, vector<vector<int>> &ans, vector<int> num, int sum, int target, int id){
        if(sum == target){
            ans.push_back(tmpans);
            return ;
        }
        for(int i = id + 1; i < num.size(); ++ i){
            if(sum + num[i] > target)
                break;
            tmpans.push_back(num[i]);
            dfs(tmpans, ans, num, sum + num[i], target, i);
            tmpans.pop_back();
            while(i + 1 < num.size() && num[i] == num[i + 1]) ++ i;
        }
    }
};
