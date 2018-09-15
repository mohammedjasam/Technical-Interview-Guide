/*
*
* Tag: BFS + Hash
* Time: O(n)
* Space: O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        lbnd = rbnd = 0;
        bfs(root, 0);
        ans.resize(mp.size());
        for(int i = lbnd; i <= rbnd; ++ i){
            ans[i - lbnd] = mp[i];
        }
        return ans;
    }

private:
    void bfs(TreeNode* root, int idx){
        queue<TreeNode*> q;
        q.push(root);
        dict[root] = idx;
        while(!q.empty()){
            TreeNode *cur = q.front();
            int cidx = dict[cur];
            q.pop();
            mp[cidx].push_back(cur->val);
            lbnd = min(lbnd, cidx);
            rbnd = max(rbnd, cidx);
            if(cur->left){
                q.push(cur->left);
                dict[cur->left] = cidx - 1;
            }
            if(cur->right){
                q.push(cur->right);
                dict[cur->right] = cidx + 1;
            }
        }
    }

private:
unordered_map<int,vector<int>> mp;
unordered_map<TreeNode*,int> dict;
int lbnd, rbnd;
};
