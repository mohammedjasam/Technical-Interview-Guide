/*
*
* Tag: DFS
* Time: O(n)
* Space: O(1) //O(logn)
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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> ans;
        if(!root)
            return ans;
        if(root->left)
            dfs(root->left, ans, k1, k2);
        if(root->val >= k1 && root->val <= k2)
            ans.push_back(root->val);
        if(root->right)
            dfs(root->right, ans, k1, k2);
        return ans;
    }
    
    void dfs(TreeNode *root, vector<int> &ans, int k1, int k2){
        if(root->left)
            dfs(root->left, ans, k1, k2);
        if(root->val >= k1 && root->val <= k2)
            ans.push_back(root->val);
        if(root->val > k2)
            return ;
        if(root->right)
            dfs(root->right, ans, k1, k2);
    }
};
