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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        double minDifference = fabs(root->val - target);
        int ans = root->val;
        
        dfs(ans, minDifference, target, root);
        
        return ans;
    }
private:
    void dfs(int &ans, double &minDifference, double target, TreeNode *root) {
        if(root->left != NULL){
            dfs(ans, minDifference, target, root->left);
        }
        
        double curDifference = fabs(root->val - target);
        if(curDifference > minDifference) {
            return ;
        }
        
        ans = root->val;
        minDifference = curDifference;
        
        if(root->right != NULL){
            dfs(ans, minDifference, target, root->right);
        }
    }
};
