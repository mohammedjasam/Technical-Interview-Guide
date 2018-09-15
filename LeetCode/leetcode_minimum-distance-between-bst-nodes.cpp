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
private:
    int minDiff;
    int lastVal, currentVal;
public:
    Solution() {
        minDiff = INT_MAX;
        lastVal = 0;
        currentVal = INT_MAX;
    }
    
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) {
            return minDiff;
        }
        
        dfs(root);
        
        return minDiff;
    }
private:
    void dfs(TreeNode* root){
        if(root->left){
            dfs(root->left);
        }
        
        lastVal = currentVal;
        currentVal = root->val;
        minDiff = min(minDiff, abs(currentVal - lastVal));
        
        if(root->right){
            dfs(root->right);
        }
    }
};
