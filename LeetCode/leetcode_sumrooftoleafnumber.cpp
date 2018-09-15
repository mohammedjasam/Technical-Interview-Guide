/*
* Algorithm: DFS
* Time complexity: O(n)
* Memory complexity: O(n)
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
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0, sum = 0;
        if(root == NULL) return ans;
        sum += root -> val;
        if(root->left!=NULL) dfs(ans,sum*10,root->left);
        if(root->right!=NULL) dfs(ans,sum*10,root->right);
        if(root->left == NULL && root->right ==NULL) ans += sum;
        return ans;
    }
    
    void dfs(int &ans, int sum, TreeNode *p){
        if(p->left==NULL && p->right==NULL){
            ans += (sum + p->val );return ;
        }
        int val = p->val;
        if(p->left!=NULL) dfs(ans,(sum + val)*10,p ->left);
        if(p->right!=NULL) dfs(ans,(sum + val)*10,p->right);
    }
};
