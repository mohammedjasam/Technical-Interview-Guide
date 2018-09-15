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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        
        root->left = pruneTree( root->left );
        root->right = pruneTree( root->right );
        
        return (!root->left && !root->right && root->val == 0)? NULL : root;
    }
    
};
