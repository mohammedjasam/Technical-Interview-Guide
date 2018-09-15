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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> ans(2, NULL);
        if(root == NULL){
            return ans;
        }
        
        if(root->val <= V) {
            ans = splitBST(root->right, V);
            root->right = ans[0];
            ans[0] = root;
        } else {
            ans = splitBST(root->left, V);
            root->left = ans[1];
            ans[1] = root;
        }
        
        return ans;
    }
};
