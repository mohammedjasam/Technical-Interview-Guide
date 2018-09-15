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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        // write your code here
        if(!root)
            return 0;
        int ans = 0;
        dfs(root);
        return max(dp[0][root], dp[1][root]);
    }
    
    void dfs(TreeNode* root){
        dp[0][root] = dp[1][root] = 0;
        dp[0][root] += root->val;
        int res = 0;
        if(root->left){
            dfs(root->left);
            res += max(dp[0][root->left], dp[1][root->left]);
            dp[0][root] += dp[1][root->left];
        }
        if(root->right){
            dfs(root->right);
            res += max(dp[0][root->right], dp[1][root->right]);
            dp[0][root] += dp[1][root->right];
        }
        dp[1][root] = res;
    }
    
private:
    unordered_map<TreeNode *,int> dp[2];
};
