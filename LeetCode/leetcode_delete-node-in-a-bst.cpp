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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        TreeNode dummy(-1);
        TreeNode *parent = NULL;
        parent = &dummy;
        parent->left = root;
        dfs(parent, root, key);
        return dummy.left;
    }
private:
    void dfs(TreeNode* parent, TreeNode* root, int key){
        if(root->val == key){
            if(!root->left && !root->right){
                if(parent->left == root)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }else if(root->right != NULL){
                TreeNode *cur = root;
                parent = root;
                root = root->right;
                while(root->left){
                    parent = root;
                    root = root->left;
                }
                cur->val = root->val;
                if(parent->right == root){
                    parent->right = root->right;
                }else{
                    parent->left = root->right;
                }
            }else{
                TreeNode *cur = root;
                parent = root;
                root = root->left;
                while(root->right){
                    parent = root;
                    root = root->right;
                }
                cur->val = root->val;
                if(parent->left == root){
                    parent->left = root->left;
                }else{
                    parent->right = root->left;
                }
            }
        }else if(root->val < key && root->right)
            dfs(root, root->right, key);
        else if(root->val > key && root->left)
            dfs(root, root->left, key);
    }
};
