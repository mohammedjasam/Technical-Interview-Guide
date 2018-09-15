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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> ans;
        if(!root)
            return ans;
        ans.push_back(root->val);
        if(root->left)
            dfs(root->left, ans);
        if(root->right)
            dfs(root->right, ans);
        return ans;
    }
    
     void dfs(TreeNode *root, vector<int> &ans){
        ans.push_back(root->val);
        if(root->left)
            dfs(root->left, ans);
        if(root->right)
            dfs(root->right, ans);
    }
    
};

