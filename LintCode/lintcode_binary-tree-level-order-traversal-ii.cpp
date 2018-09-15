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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderButtom(TreeNode *root) {
        // write your code her
        vector<vector<int>> ans;
        stack<vector<int>> st;
        if(!root)
            return ans;
        vector<TreeNode *> q;
        int front = 0, rear = 0, lvrear = 0;
        q.push_back(root);
        ++ rear;
        ++ lvrear;
        while(front < rear){
            vector<int> tmpans;
            int idx;
            idx = front;
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
            front = rear;
            rear = lvrear;
            st.push(tmpans);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
