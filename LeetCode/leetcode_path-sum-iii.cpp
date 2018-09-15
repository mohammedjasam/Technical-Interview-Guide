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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> dict;
        return dfs(root, sum, dict, 0);
    }
private:
    int dfs(TreeNode *root, int &sum, unordered_map<int,int> &dict, int presum){
        if(!root)
            return 0;
        int res = 0;
        root->val += presum;
        res = (root->val == sum) + (dict.count(root->val - sum)?dict[root->val - sum]:0);
        ++ dict[root->val];
        res += dfs(root->left, sum, dict, root->val) + dfs(root->right, sum, dict, root->val);
        -- dict[root->val];
        return res;
    }
    
};
