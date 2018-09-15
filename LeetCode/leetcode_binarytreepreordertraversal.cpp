/*
* Algorithm: dfs
* Time Complexity: O(n)
* Memory Complexity: O(n)
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        dfs(root, ans);
        return ans;
    }
    
    void dfs(TreeNode *node, vector<int> &ans){
        ans.push_back(node->val);
        if(node->left)
            dfs(node->left, ans);
        if(node->right)
            dfs(node->right, ans);
    }
};

