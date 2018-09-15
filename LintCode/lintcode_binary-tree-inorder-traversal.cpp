/*
*
* Tag: DFS
* Time: O(n)
* Space: O(lgn)
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> ans;
        if(!root)
            return ans;
        if(root->left)
            dfs(root->left, ans);
        ans.push_back(root->val);
        if(root->right)
            dfs(root->right, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, vector<int> &ans){
        if(root->left)
            dfs(root->left, ans);
        ans.push_back(root->val);
        if(root->right)
            dfs(root->right, ans);
    }
};
