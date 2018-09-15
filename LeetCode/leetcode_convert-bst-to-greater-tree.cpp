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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        int tot = 0;
        dfs(root, tot);
        return root;
    }
private:
    void dfs(TreeNode *root, int &tot){
        if(root->right){
            dfs(root->right, tot);
        }
        tot += root->val;
        root->val += (tot - root->val);
        if(root->left){
            dfs(root->left, tot);
        }
    }
};
