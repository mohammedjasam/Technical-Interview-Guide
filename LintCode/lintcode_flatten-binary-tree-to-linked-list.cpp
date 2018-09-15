/*
*
* Tag: DFS
* Time: O(n)
* Space: O(1)
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        if(!root)
            return ;
        Convert(root);
    }
    
    TreeNode *Convert(TreeNode *root){
        if(!root->left && !root->right)
            return root;
        TreeNode *lhead = NULL, *rhead = NULL;
        if(root->right)
            rhead = Convert(root->right);
        TreeNode *tmpnode = root;
        if(root->left){
            lhead = Convert(root->left);
            root->right = lhead;
            root->left = NULL;
            lhead->left = NULL;
            while(tmpnode->right)
                tmpnode = tmpnode->right;
        }
        if(rhead){
            tmpnode->right = rhead;
            rhead->left = NULL;
        }
        return root;
    }
};
