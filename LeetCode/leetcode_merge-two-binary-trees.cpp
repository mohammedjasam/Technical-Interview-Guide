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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *root = NULL;
        dfs(&root, t1, t2);
        return root;
    }
private:
    inline void dfs(TreeNode **root, TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2)
            root = NULL;
        else if(t1 && !t2){
            *root = t1;
        }else if(!t1 && t2)
            *root = t2;
        else{
            
            *root = new TreeNode(t1->val + t2->val);
            dfs(&((*root)->left), t1->left, t2->left);
            dfs(&((*root)->right), t1->right, t2->right);
        }
    }
};
