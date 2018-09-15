/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> ans;
        if(candidates.size() == 0)
            return ans;
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); ++ i){
            vector<int> tmpans;
            int sum = 0;
            sum += candidates[i];
            if(sum == target){
                tmpans.push_back(candidates[i]);
                ans.push_back(tmpans);
            }else if(sum < target){
                tmpans.push_back(candidates[i]);
                dfs(candidates, tmpans, ans, sum, target, i);
            }else
                break;
            while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1] ) ++ i;
        }
    }
    
    void dfs(vector<int> candidates, vector<int> &tmpans, vector<vector<int>> &ans, int sum, int target, int id){
        for(int i = id; i < candidates.size(); ++ i){
            if(sum + candidates[i] > target)
                return ;
            else if(sum + candidates[i] == target){
                tmpans.push_back(candidates[i]);
                ans.push_back(tmpans);
                tmpans.pop_back();
            }else{
                sum += candidates[i];
                tmpans.push_back(candidates[i]);
                dfs(candidates, tmpans, ans, sum, target, i);
                tmpans.pop_back();
                sum -= candidates[i];
            }
            while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1] ) ++ i;
        }
    }
};
