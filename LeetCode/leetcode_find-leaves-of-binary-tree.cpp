/*
*
* Tag: Topological Sort
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<TreeNode *> q;
        int fnt = 0, rear = 0;
        prev.clear();
        cnt = 0;
        dfs(root, NULL, q, rear);
        st.clear();
        while(fnt < rear){
            vector<int> tmp;
            int nrear = rear;
            while(fnt < rear){
                TreeNode *u = q[fnt ++];
                tmp.push_back(u->val);
                if(prev[u]){
                    -- deg[prev[u]];
                }
                if(prev[u] && st.find(prev[u]) == st.end() && !deg[prev[u]]){
                    q.push_back(prev[u]);
                    st.insert(prev[u]);
                    ++ nrear;
                }
            }
            rear = nrear;
            ans.push_back(tmp);
        }
        return ans;
    }
    
private:
    void dfs(TreeNode* root, TreeNode *parent, vector<TreeNode *> &q, int &rear){
        prev[root] = parent;
        ++ cnt;
        if(root->left){
            dfs(root->left, root, q, rear);
            ++ deg[root];
        }
        if(root->right){
            dfs(root->right, root, q, rear);
            ++ deg[root];
        }
        if(!root->left && !root->right){
            q.push_back(root);
            ++ rear;
            deg[root] = 0;
        }
    }
private:
    unordered_map<TreeNode *, TreeNode *> prev;
    unordered_map<TreeNode *, int> deg;
    unordered_set<TreeNode *> st;
    int cnt;
};
