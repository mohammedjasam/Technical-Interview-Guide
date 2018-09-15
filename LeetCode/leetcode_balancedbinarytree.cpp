/*
* Algorithm: DFS
* Time complexity: O(n)
* Memory complexity: O(1)
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return true;
        int l = 0, r = 0;
        bool flag = true;
        if(root->left!=NULL) l = dfs(root->left,flag);
        if(flag && root->right!=NULL) r = dfs(root->right,flag);
        if(!flag) return false;
        if(abs(l - r) <= 1) return true;
        return false;
    }
    
    int dfs(TreeNode *p,bool &flag){
        int l = 0, r = 0;
        if(p->left!=NULL) l = dfs(p->left,flag);
        if(flag && p->right!=NULL) r = dfs(p->right,flag);
        if(!flag) return 0;
        if(abs(l - r) > 1) {flag=false;return 0;}
        return max(l,r) + 1;
    }
};
