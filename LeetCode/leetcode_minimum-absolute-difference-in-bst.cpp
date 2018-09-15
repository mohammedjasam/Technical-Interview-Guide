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
    int getMinimumDifference(TreeNode* root) {
        int last_v = -1, cur_v, ans = INT_MAX;
        dfs(root, last_v, ans);
        
        return ans;
    }
private:
    void dfs(TreeNode *root, int &last_v, int &ans){
        if(root->left) {
            dfs(root->left, last_v, ans);
        }
        
        if(last_v >= 0){
            ans = min(ans, root->val - last_v);
        }
        last_v = root->val;
        
        if(root->right) {
            dfs(root->right, last_v, ans);
        }
    }
};
