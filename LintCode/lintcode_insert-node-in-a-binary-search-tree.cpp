/*
*
* Tag: DFS
* Time: O(lgn) (Worst: O(n))
* Space: O(lgn)
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(!root){
            root = node;
            return root;
        }
        if(!node)
            return root;
        dfs(root, node);
        return root;
    }
    
    void dfs(TreeNode* root, TreeNode *node){
        if(node->val <= root->val){
            if(root->left)
                dfs(root->left, node);
            else
                root->left = node;
        }else{
            if(root->right)
                dfs(root->right, node);
            else
                root->right = node;
        }
    }
};
