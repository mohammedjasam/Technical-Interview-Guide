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
    int findTilt(TreeNode* root) {
        int sum = 0;
        if(root == NULL)
            return sum;
        dfs(root, sum);
        return sum;
    }
private:
    int dfs(TreeNode* root, int &sum){
        int lsum = 0, rsum = 0;
        if(root->left)
            lsum = dfs(root->left, sum);
        if(root->right)
            rsum = dfs(root->right, sum);
        sum += abs(lsum - rsum);
        return lsum + rsum + root->val;
    }
};
