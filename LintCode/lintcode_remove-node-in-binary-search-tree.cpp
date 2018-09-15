/*
*
* Tag: DFS
* Time: O(lgn)
* Space: O(lgn)
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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(!root)
            return root;
        TreeNode parent(-1);
        TreeNode *p = &parent;
        p->left = root;
        if(root->left && root->val > value)
            dfs(root->left, root, value, 1);
        else if(root->val == value){
            if(!root->left && !root->right)
                p->left = NULL;
            else{
                if(!root->left)
                    p->left = root->right;
                else if(!root->right)
                    p->left = root->left;
                else{
                    stack<TreeNode *> st;
                    TreeNode *q = root->right;
                    st.push(q);
                    while(q){
                        q = q->left;
                        if(!q){
                            q = st.top();
                            st.pop();
                            if(!st.empty()){
                                TreeNode *u = st.top();
                                u->left = NULL;
                            }else{
                                root->left = NULL;
                            }
                            q->left = root->left;
                            q->right = root->right;
                            p->left = q;
                            break;
                        }else{
                            st.push(q);
                        }
                    }
                }
            }
        }else if(root->right && root->val < value)
            dfs(root->right, root, value, 0);
        return parent.left;
    }
    
    void dfs(TreeNode* root, TreeNode* parent,int value, bool isleft){
        if(!root)
            return ;
        if(root->left && root->val > value)
            dfs(root->left, root, value, 1);
        else if(root->val == value){
            if(!root->left && !root->right){
                if(isleft)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }else{
                if(!root->left){
                    if(isleft)
                        parent->left = root->right;
                    else
                        parent->right = root->right;
                }else if(!root->right){
                    if(isleft)
                        parent->left = root->left;
                    else
                        parent->right = root->left;
                }else{
                    stack<TreeNode *> st;
                    TreeNode *q = root->right;
                    st.push(q);
                    while(q){
                        q = q->left;
                        if(!q){
                            q = st.top();
                            st.pop();
                            if(!st.empty()){
                                TreeNode *u = st.top();
                                u->left = NULL;
                            }else{
                                root->left = NULL;
                            }
                            q->left = root->left;
                            q->right = root->right;
                            if(isleft)
                                parent->left = q;
                            else
                                parent->right = q;
                    //        p->left = q;
                            break;
                        }else{
                            st.push(q);
                        }
                    }
                }
            }
        }else if(root->right && root->val < value)
            dfs(root->right, root, value, 0);
    }
    
};
