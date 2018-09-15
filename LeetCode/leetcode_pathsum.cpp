/*
* Algorithm: dfs
* Time complexity: O(n)
* Memory complexity: O(n)
*
*/
/*
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
    bool hasPathSum(TreeNode *root, int sum) {
        int sum_val = 0;
        bool isexit = false;
        if(root == NULL)
            return false;
        dfs(root, sum, sum_val, isexit);
        return isexit;
    }
    
    void dfs(TreeNode *root, int sum, int sum_val, bool &isexit){
        if(root->left == NULL && root->right == NULL){
            if(sum_val + root->val == sum)
                isexit = true;
            return ;
        }
        if(root->left)
            dfs(root->left, sum, sum_val + root->val, isexit);
        if(root->right)
            dfs(root->right, sum, sum_val + root->val, isexit);
    }
};

