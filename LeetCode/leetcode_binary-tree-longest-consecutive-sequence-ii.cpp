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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        if(root == NULL)
            return ans;
        unordered_map<TreeNode *, pair<int,int>> dict;
        dfs(root, dict, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, unordered_map<TreeNode *, pair<int,int>> &dict, int &ans){
        dict[root] = make_pair(0, 0);
        pair<int,int> lp(1, 1), rp(1, 1);
        if(root->left){
            dfs(root->left, dict, ans);
            if(root->val - root->left->val == 1)
                lp.first += dict[root->left].first;
            else if(root->val - root->left->val == -1)
                lp.second += dict[root->left].second;
        }
        ans = max(ans, max(lp.first, lp.second));
        if(root->right){
            dfs(root->right, dict, ans);
            if(root->val - root->right->val == 1)
                rp.first += dict[root->right].first;
            else if(root->val - root->right->val == -1)
                rp.second += dict[root->right].second;
        }
        ans = max(ans, max(rp.first, rp.second));
        ans = max(ans, max(lp.first + rp.second - 1, lp.second + rp.first - 1));
        dict[root].first = max(lp.first, rp.first);
        dict[root].second = max(lp.second, rp.second);
    }
};
