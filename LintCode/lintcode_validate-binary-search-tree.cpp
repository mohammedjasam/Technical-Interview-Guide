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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        vector<TreeNode *> arr;
        if(!root)
            return true;
        if(root->left){
            if(!dfs(root->left, arr))
                return false;
            if(root->val <= arr[arr.size() - 1]->val)
                return false;
        }
        arr.push_back(root);
        if(root->right){
            if(!dfs(root->right, arr))
                return false;
        }
        return true;
    }
    
    bool dfs(TreeNode *root, vector<TreeNode *> &arr){
        if(root->left){
            if(!dfs(root->left, arr))
                return false;
            if(root->val <= arr[arr.size() - 1]->val)
                return false;
        }
        if(arr.size() >= 1){
            if(root->val <= arr[arr.size() - 1]->val)
                return false;
        }
        arr.push_back(root);
        if(root->right){
            if(!dfs(root->right, arr))
                return false;
        }
        return true;
    }
};
