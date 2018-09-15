/*
* Algorithm: BFS
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        if(p == NULL && q == NULL) return true;
        if((p == NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode *t1 = q1.front();
            q1.pop();
            TreeNode *t2 = q2.front();
            q2.pop();
            if((t1->val != t2->val) || (t1->left == NULL && t2->left != NULL) || (t1->left != NULL && t2->left == NULL) || 
               (t1->right == NULL && t2->right!=NULL) || (t1->right != NULL && t2->right ==NULL)) return false;
            if(t1->left!=NULL) {
                q1.push(t1->left);
                q2.push(t2->left);
            }
            if(t1->right!=NULL) {
                q1.push(t1->right);
                q2.push(t2->right);
            }
         }
         return true;
    }
};
