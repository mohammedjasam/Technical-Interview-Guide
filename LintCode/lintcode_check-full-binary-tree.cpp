/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /*
     * @param : the given tree
     * @return: Whether it is a full tree
     */
    bool isFullTree(TreeNode * root) {
        return root == NULL? true: hasOnlyOneChild(root)? false: isFullTree(root->left) && isFullTree(root->right);
    }
private:
    bool hasOnlyOneChild(TreeNode *root){
        return (root->left != NULL && root->right == NULL) || 
        (root->left == NULL && root->right != NULL);
    }
};
