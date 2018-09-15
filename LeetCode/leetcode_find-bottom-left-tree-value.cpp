/*
*
* Tag: DFS
* Time: O(n)
* Space: O(h)
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0, h = -1;
        dfs(root, ans, h, 0);
        return ans;
    }
private:
    void dfs(TreeNode* root, int &ans, int &h, int dep){
        if(dep > h){
            ans = root->val;
            h = dep;
        }
        if(root->left)
            dfs(root->left, ans, h, dep + 1);
        if(root->right)
            dfs(root->right, ans, h, dep + 1);
    }
};
