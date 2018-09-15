/*
*
* Tag: DFS
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> tmpans;
        dfs(root, 0, target, tmpans, ans);
        return ans;
    }
    
private:
    void dfs(TreeNode *root, int sum, int target, vector<int> tmpans, vector<vector<int>> &ans){
        sum += root->val;
        tmpans.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == target)
                ans.push_back(tmpans);
            return ;
        }
        
        if(root->left)
            dfs(root->left, sum, target, tmpans, ans);
        if(root->right)
            dfs(root->right, sum, target, tmpans, ans);
    }
};
