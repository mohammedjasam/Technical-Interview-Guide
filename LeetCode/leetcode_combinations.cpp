/*
* Algorithm: DFS
* Time complexity: O(n^2)
* Memory complexity: O(n^2)
*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ans;
        if(k>n) return ans;
        vector<int> tmp_ans;
        tmp_ans.clear();
        for(int i = 1; i <= n; i ++){
            tmp_ans.push_back(i);
            dfs(ans,tmp_ans,i,n,1,k);
            tmp_ans.pop_back();
        }
        return ans;
    }
    void dfs(vector<vector<int> > &ans,vector<int> &tmp_ans,int sta,int len,int dep,int enddep){
        if(dep >= enddep){
            ans.push_back(tmp_ans);
            return;
        }
        for(int i = sta + 1; i <= len; i ++){
            tmp_ans.push_back(i);
            dfs(ans,tmp_ans,i,len,dep+1,enddep);
            tmp_ans.pop_back();
        }
    }
};
