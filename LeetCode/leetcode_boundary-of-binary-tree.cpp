/*
*
* Tag: DFS
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        ans.push_back(root->val);
        lbnd(root->left, ans);
        dfs(root->left, ans);
        dfs(root->right, ans);
        rbnd(root->right, ans);
        return ans;
    }
private:
    void lbnd(TreeNode *root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return ;
        ans.push_back(root->val);
        if(root->left)
            lbnd(root->left, ans);
        else
            lbnd(root->right, ans);
    }
    
    void rbnd(TreeNode *root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return ;
        if(root->right)
            rbnd(root->right, ans);
        else
            rbnd(root->left, ans);
        ans.push_back(root->val);
    }
    
    void dfs(TreeNode *root, vector<int> &ans){
        if(root == NULL)
            return ;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->val);
            return ;
        }
        if(root->left)
            dfs(root->left, ans);
        if(root->right)
            dfs(root->right, ans);
    }
};
