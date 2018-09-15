/*
*
* Tag: DFS
* Time: O(2^n)
* Space: O(n)
*/
class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // write your code her
        vector<vector<int>> ans(1);
        if(S.size() == 0)
            return ans;
        sort(S.begin(), S.end());
        int n = S.size();
        for(int i = 0; i < n; ++ i){
            vector<int> tmpans;
            tmpans.push_back(S[i]);
            ans.push_back(tmpans);
            dfs(tmpans, ans, S, i);
            while(i + 1 < n && S[i] == S[i + 1]) ++ i;
        }
        return ans;
    }
    
    void dfs(vector<int> &tmpans, vector<vector<int>> &ans, vector<int> S, int id){
        int n = S.size();
        for(int i = id + 1; i < n; ++ i){
            tmpans.push_back(S[i]);
            ans.push_back(tmpans);
            dfs(tmpans, ans, S, i);
            while(i + 1 < n && S[i] == S[i + 1]) ++ i;
            tmpans.pop_back();
        }
    }
};

