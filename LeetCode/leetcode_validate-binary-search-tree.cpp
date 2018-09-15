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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }
    
    bool isValidBST(TreeNode *root, long long low, long long up){
        if(root == NULL) return true;
        
        return root->val > low && root->val < up
                && isValidBST(root->left, low, root->val)
                && isValidBST(root->right, root->val, up);
    }
};
