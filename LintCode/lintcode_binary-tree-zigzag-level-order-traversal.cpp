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
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code her
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<TreeNode *> q;
        int front = 0, rear = 0, lvrear = 0;
        q.push_back(root);
        ++ rear;
        ++ lvrear;
        bool l2r = true;
        while(front < rear){
            vector<int> tmpans;
            int idx;
            if(l2r){
                idx = front;
                l2r = false;
                for(; idx < rear; ++ idx){
                    TreeNode *u = q[idx];
                    tmpans.push_back(u->val);
                    if(u->left){
                        q.push_back(u->left);
                        ++ lvrear;
                    }
                    if(u->right){
                        q.push_back(u->right);
                        ++ lvrear;
                    }
                }
            }else{
                idx = rear - 1;
                l2r = true;
                for(; idx >= front; -- idx){
                    TreeNode *u = q[idx];
                    tmpans.push_back(u->val);
                }
                idx = front;
                for(; idx < rear; ++ idx){
                    TreeNode *u = q[idx];
                    if(u->left){
                        q.push_back(u->left);
                        ++ lvrear;
                    }
                    if(u->right){
                        q.push_back(u->right);
                        ++ lvrear;
                    }
                }
            }
            front = rear;
            rear = lvrear;
            ans.push_back(tmpans);
        }
        return ans;
    }
};
