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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL) return 0;
        vector<TreeNode *> que;
        int ans = 0;
        int front  = 0,rear  = 0;
        que.push_back(root);
        rear ++;
        while(front < rear){
            int back = rear;
            ans ++;
            bool flag = false;
            while(front < back){
                TreeNode *p = que[front];
                front ++;
                if(p->left == NULL && p->right == NULL){
                    flag = true;
                    break;
                }
                if(p->left!=NULL) {que.push_back(p->left);rear ++;}
                if(p->right!=NULL) {que.push_back(p->right);rear ++;}
            }
            if(flag) break;
        }
        return ans;
    }
};
