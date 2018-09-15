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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)){
            return false;
        }
        
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        
        return leaf1 == leaf2;
    }
    
private:
    void dfs(TreeNode* root, vector<int> &leaf){
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root->val);
            return ;
        }
        
        dfs(root->left, leaf);
        dfs(root->right, leaf);
    }
};
