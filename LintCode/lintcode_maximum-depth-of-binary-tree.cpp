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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        int depth = 0;
        if(!root)
            return depth;
        vector<TreeNode *> q;
        int front = 0, rear = 0;
        q.push_back(root);
        ++ rear;
        while(front < rear){
            vector<TreeNode *> tmpq;
            int tmprear = 0;
            ++ depth;
            while(front < rear){
                TreeNode *u = q[front ++];
                if(u->left){
                    tmpq.push_back(u->left);
                    ++ tmprear;
                }
                if(u->right){
                    tmpq.push_back(u->right);
                    ++ tmprear;
                }
            }
            q = tmpq;
            rear = tmprear;
            front = 0;
        }
        return depth;
    }
};
