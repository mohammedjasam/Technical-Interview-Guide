/*
*
* Tag: DP
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
    int rob(TreeNode* root) {
        int ans = 0;
        if(!root)
            return ans;
        dp.clear();
        dfs(root);
        ans = max(dp[root].first, dp[root].second);
        return ans;
    }
    
    void dfs(TreeNode *root){
        int res = 0;
        dp[root].first = root->val;
        dp[root].second = 0;
        if(root->left){
            dfs(root->left);
            dp[root].first += dp[root->left].second;
            dp[root].second += max(dp[root->left].first, dp[root->left].second);
        }
        if(root->right){
            dfs(root->right);
            dp[root].first += dp[root->right].second;
            dp[root].second += max(dp[root->right].first, dp[root->right].second);
        }
    }
    
private:
    unordered_map<TreeNode *, pair<int,int> > dp;
};
