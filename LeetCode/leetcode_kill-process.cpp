/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ans;
        if(pid.size() == 0 || ppid.size() == 0)
            return ans;
        unordered_map<int,unordered_set<int>> pid_tree;
        int n = pid.size();
        for(int i = 0; i < n; ++ i){
            pid_tree[ppid[i]].insert(pid[i]);
        }
        dfs(kill, pid_tree, ans);
        return ans;
    }
private:
    void dfs(int u, unordered_map<int,unordered_set<int>> &pid_tree, vector<int> &ans){
        ans.push_back(u);
        if(pid_tree[u].size() == 0)
            return ;
        for(auto it = pid_tree[u].begin(); it != pid_tree[u].end(); ++ it){
            dfs(*it, pid_tree, ans);
        }
    }
};
