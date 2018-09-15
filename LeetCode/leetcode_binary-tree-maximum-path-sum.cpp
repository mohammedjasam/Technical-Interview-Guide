/*
*
* Tag: Tree DP
* Time: O(n)
* Space: O(n)
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
    int maxPathSum(TreeNode *root) {
        res = INT_MIN;
        dfs(root);
        return res;
    }

private:
    int res;
    int dfs(TreeNode *root){
        if(root == NULL) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        int sum = root->val;
        if(l > 0) sum += l;
        if(r > 0) sum += r;
        res = max(res, sum);
        return max(l, r) > 0?max(l, r) + root->val:root->val;
    }
};
