/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(!root)
            return true;
        int len_l = 0, len_r = 0;
        if(root->left){
            if(!dfs(root->left, len_l))
                return false;
        }
        if(root->right){
            if(!dfs(root->right, len_r))
                return false;
        }
        if(abs(len_l - len_r) < 2)
            return true;
        else
            return false;
    }
    
    bool dfs(TreeNode *root, int &len){
        if(!root){
            len = 1;
            return true;
        }
        int len_l = 0, len_r = 0;
        if(root->left){
            if(!dfs(root->left, len_l))
                return false;
        }
        if(root->right){
            if(!dfs(root->right, len_r))
                return false;
        }
        if(abs(len_l - len_r) < 2){
            len = max(len_l, len_r) + 1;
            return true;
        }else
            return false;
    }
};
