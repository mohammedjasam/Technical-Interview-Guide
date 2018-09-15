/*
* Algorithm: DFS
* Time complexity: O(n)
* Memory complexity: O(1)
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
    void flatten(TreeNode *root) {
        if(root == NULL)
            return ;
        Convert(root);
    }
    
    TreeNode *Convert(TreeNode *node){
        if(node->left == NULL && node->right == NULL)
            return node;
        TreeNode *rHead = NULL;
        if(node->right != NULL)
            rHead = Convert(node->right);
        TreeNode *tmpnode = node;
        if(node->left != NULL){
            TreeNode *lHead = Convert(node->left);
            node->right = lHead;
            node->left = NULL;
            lHead->left = NULL;
            while(tmpnode->right != NULL)
                tmpnode = tmpnode->right;
        }
        if(rHead != NULL){
            tmpnode->right = rHead;
            rHead->left = NULL;
        }
        return node;
    }
};
