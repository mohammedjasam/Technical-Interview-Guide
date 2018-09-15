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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if(root == NULL)
            return ans;
        vector<TreeNode *> que;
        int front = 0, level_rear = 0, que_rear = 0;
        int level_cnt = 0;
        int l_to_r = 1;
        que.push_back(root);
        level_rear = que_rear = 1;
        while(front < que_rear){
            vector<int> tmp_ans;
            TreeNode *tmp;
            if(l_to_r){
                for(int i = front; i < level_rear; i ++){
                    tmp = que[i];
                    tmp_ans.push_back(tmp->val);
                }
            }else{
                for(int i = level_rear - 1; i >= front; i --){
                    tmp = que[i];
                    tmp_ans.push_back(tmp->val);
                }
            }
            while(front < level_rear){
                TreeNode *top = que[front];
                front ++;
                if(top->left){
                    que.push_back(top->left);
                    que_rear ++;
                }
                if(top->right){
                    que.push_back(top->right);
                    que_rear ++;
                }
            }
            ans.push_back(tmp_ans);
            level_rear = que_rear;
            l_to_r = (l_to_r + 1)%2;
        }
        return ans;
    }
};
