/*
*
* Tag: Tree DP
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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int ans = INT_MIN, sum;
        if(!root)
            return 0;
        dfs(root, ans, sum);
        return ans;
    }
    
    void dfs(TreeNode *root, int &ans, int &sum){
        int left_sum = 0, right_sum = 0;
        if(root->left){
            dfs(root->left, ans, left_sum);
             ans = max(ans, left_sum);
        }
        if(root->right){
            dfs(root->right, ans, right_sum);
            ans = max(ans, right_sum);
        }
        
        ans = max(ans, root->val);
        ans = max(ans, left_sum + root->val);
        ans = max(ans, right_sum + root->val);
        ans = max(ans, left_sum + right_sum + root->val);
        sum = max(left_sum + root->val, right_sum + root->val);
    }
};
