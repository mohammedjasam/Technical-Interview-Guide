/*
*
* Tag: BFS
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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        int depth = 0;
        if(!root)
            return depth;
        vector<TreeNode *> q;
        int front = 0, rear = 0;
        q.push_back(root);
        rear ++;
        while(front < rear){
            vector<TreeNode *> tmpq;
            int tmp_rear = 0;
            ++ depth;
            bool noleaf = true;
            while(front < rear){
                TreeNode *u = q[front ++];
                if(u->left){
                    tmpq.push_back(u->left);
                    tmp_rear ++;
                }
                if(u->right){
                    tmpq.push_back(u->right);
                    tmp_rear ++;
                }
                if(!u->left && !u->right){
                    noleaf = false;
                    break;
                }
            }
            if(!noleaf)
                break;
            q = tmpq;
            front = 0;
            rear = tmp_rear;
        }
        return depth;
    }
};
