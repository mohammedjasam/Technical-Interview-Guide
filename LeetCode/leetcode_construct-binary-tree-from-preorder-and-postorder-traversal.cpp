/*
*
* Tag: DFS
* Time: O(nlgn)
* Space: O(nlgn)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode *root = NULL;
        if(pre.empty() || post.empty()){
            return root;
        }
        
        root = new TreeNode(pre[0]);
        if(pre.size() > 1){
            int leftSubTreeSize = 0, leftTreeRootVal = pre[1];
            for(int i = 0; i < post.size(); ++ i){
                ++ leftSubTreeSize;
                if(post[i] == leftTreeRootVal){
                    break;
                }
            }
            vector<int> leftSubTreePre(pre.begin() + 1, pre.begin() + leftSubTreeSize + 1), leftSubTreePost(post.begin(), post.begin() + leftSubTreeSize);
            root->left = constructFromPrePost(leftSubTreePre, leftSubTreePost);
            
            int rightSubTreeSize = pre.size() - leftSubTreeSize - 1;
            vector<int> rightSubTreePre(pre.begin() + leftSubTreeSize + 1, pre.end()), rightSubTreePost(post.begin() + leftSubTreeSize, post.begin() + leftSubTreeSize + rightSubTreeSize);
            root->right = constructFromPrePost(rightSubTreePre, rightSubTreePost);
        }
        
        return root;
    }
};

/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.empty() || post.empty()){
            return NULL;
        }
        
        vector<TreeNode *> stk;
        stk.push_back(new TreeNode(pre[0]));
        for(int i = 1, j = 0; i < pre.size(); ++ i){
            TreeNode *node = new TreeNode(pre[i]);
            while(stk.back()->val == post[j]) {
                ++ j;
                stk.pop_back();
            }
            
            if(stk.back()->left == NULL) {
                stk.back()->left = node;
            } else {
                stk.back()->right = node;
            }
            stk.push_back(node);
        }
        
        return stk[0];
    }
};
