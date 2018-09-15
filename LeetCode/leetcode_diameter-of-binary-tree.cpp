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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0, height = 0;
        if(root == NULL)
            return ans;
        dfs(root, ans, height);
        return ans;
    }
private:
    void dfs(TreeNode *root, int &ans, int &height){
        int l_height = 0, r_height = 0;
        if(root->left){
            dfs(root->left, ans, l_height);
        }
        if(root->right){
            dfs(root->right, ans, r_height);
        }
        ans = max(ans, l_height + r_height);
        height = max(l_height, r_height) + 1;
    }
};
