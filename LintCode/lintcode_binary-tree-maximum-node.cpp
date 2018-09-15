/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    TreeNode *ans;
public:
    /**
     * @param root the root of binary tree
     * @return the max node
     */
    TreeNode* maxNode(TreeNode* root) {
        // Write your code here
        ans = root;
        if(root != NULL){
            int cmpval = root->val;
            dfs(root, cmpval);
        }
        return ans;
    }
private:
    void dfs(TreeNode* root, int &cmpval){
        if(cmpval < root->val){
            cmpval = root->val;
            ans = root;
        }
        if(root->left)
            dfs(root->left, cmpval);
        if(root->right)
            dfs(root->right, cmpval);
    }
};
