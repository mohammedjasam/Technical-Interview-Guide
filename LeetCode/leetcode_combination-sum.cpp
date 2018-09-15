/*
*
* Tag: DFS
* Time: O(n^n)
* Space: O(n) without considering space for output.
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans;
        if(candidates.size() == 0 || target <= 0){
            return ans;
        }
        
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); i ++){
            if(candidates[i] > target)
                break;
            int sum = candidates[i];
            vector<int> combination;
            combination.push_back(candidates[i]);
            dfs(sum, combination, candidates, target, ans, i);
        }
        
        return ans;
    }
    
    void dfs(int sum, vector<int> combination, vector<int> &candidates, int target, vector<vector<int> > &ans, int idx){
        if(sum == target){
            ans.push_back(combination);
            return ;
        }
        
        for(int i = idx; i < candidates.size(); i ++){
            if(sum + candidates[i] > target)
                return ;
            combination.push_back(candidates[i]);
            dfs(sum + candidates[i], combination, candidates, target, ans, i);
            combination.pop_back();
        }
    }
};
