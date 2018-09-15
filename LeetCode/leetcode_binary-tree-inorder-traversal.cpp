/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    
    void dfs(TreeNode *p, vector<int> &ans){
        if(p == NULL) {
            return ;
        }
        if(p->left!=NULL) {
            dfs(p->left,ans);
        }
        
        ans.push_back(p->val);
        
        if(p->right!=NULL) {
            dfs(p->right,ans);
        }
    }
};
