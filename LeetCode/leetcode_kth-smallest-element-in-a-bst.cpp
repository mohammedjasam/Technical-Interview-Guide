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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, cnt = 0;
        dfs(root, cnt, k, ans);
        return ans;
    }
    
    
    void dfs(TreeNode* root, int &cnt, int k, int &ans){
        if(root->left)
            dfs(root->left, cnt, k, ans);
        if(cnt == k)
            return ;
        ++ cnt;
        if(cnt == k){
            ans = root->val;
            return ;
        }
        if(root->right)
            dfs(root->right, cnt, k, ans);
        return ;
    }
};
