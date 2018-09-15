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
    string tree2str(TreeNode* t) {
        string ans = "";
        if(t == NULL){           
            return ans;
        }
        dfs(t, ans);
        return ans;
    }
private:
    inline void dfs(TreeNode *t, string &ans) {
        ans += to_string(t->val);
        if(t->left == NULL && t->right == NULL) {
            return ;
        }
        if(t->left){
            ans += "(";
            dfs(t->left, ans);
            ans += ")";
        } else {
            ans += "()";
        }
        if(t->right) {
            ans += "(";
            dfs(t->right, ans);
            ans += ")";
        }
    }
};
