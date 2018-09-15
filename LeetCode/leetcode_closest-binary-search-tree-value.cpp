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
    int closestValue(TreeNode* root, double target) {
        double diff = (double)LLONG_MAX;
        int ans;
        dfs(root, ans, diff, target);
        return ans;
    }
private:
    void dfs(TreeNode* root, int &ans, double diff, double target){
        double dis = abs(root->val - target);
        if(dis < diff){
            diff = dis;
            ans = root->val;
        }
        if(target > root->val){
            if(!root->right)
                return ;
            dfs(root->right, ans, diff, target);
        }else{
            if(!root->left)
                return ;
            dfs(root->left, ans, diff, target);
        }
    }
};
