/*
* Algorithm: dfs
* Time complexity: O(n)
* Memory complexity: O(n)
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        dfs(root, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, vector<int> &ans){
        if(root->left)
            dfs(root->left, ans);
        if(root->right)
            dfs(root->right, ans);
        ans.push_back(root->val);
    }
    
};

