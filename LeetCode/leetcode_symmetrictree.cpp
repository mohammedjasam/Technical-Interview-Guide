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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return true;
        vector<TreeNode *> que;
        int front = 0, rear = 0;
        que.push_back(root);
        rear ++;
        while(front < rear){
            int back = rear;
            int i = front, j = back - 1;
            while(i <= j){
                TreeNode *p = que[i], *q = que[j];
                if(p->left!=NULL && q->right == NULL) return false;
                if(p->left==NULL && q->right != NULL) return false;
                if(p->right!=NULL && q->left == NULL) return false;
                if(p->right==NULL && q->left != NULL) return false;
                if(p->left!=NULL){
                    if(p->left->val != q->right->val) return false;
                }
                if(p->right!=NULL){
                    if(p->right->val != q->left->val) return false;
                }
                i ++; j --;
            }
            while(front <back){
                TreeNode *p = que[front];
                front ++;
                if(p->left!=NULL) {que.push_back(p->left);rear ++;}
                if(p->right!=NULL) {que.push_back(p->right);rear ++;}
            }
        }
        return true;
    }
};
