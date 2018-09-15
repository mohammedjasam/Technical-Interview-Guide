/*
*
* Tag: Stack (Data Structure)
* Time: Next: O(n); HasNext: O(1)
* Space: O(n)
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
class BSTIterator {
private:
    stack<TreeNode *> traceStack;
public:
    BSTIterator(TreeNode *root) {
        if(root == NULL){
            return ;
        }
        
        TreeNode *p = root;
        traceStack.push(p);
        while(p->left){
            p = p->left;
            traceStack.push(p);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !traceStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = traceStack.top();
        traceStack.pop();
        int ans = p->val;
        if(p->right){
            p = p->right;
            traceStack.push(p);
            while(p->left){
                p = p->left;
                traceStack.push(p);
            }
        }
        
        return ans;
    }
};
