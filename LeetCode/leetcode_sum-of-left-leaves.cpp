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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, int &ans){
        if(root == NULL)
            return ;
        if(root->left != NULL){
            TreeNode* tmp = root->left;
            if(tmp->left == NULL && tmp->right == NULL){
                ans += tmp->val;
            }else
                dfs(root->left, ans);
        }
        if(root->right)
            dfs(root->right, ans);
    }
};
