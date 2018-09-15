/*
*
* Tag: DFS
* Time: O(n^2)
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        TreeNode *root = new TreeNode(0);
        if(postorder.size() == 0 || inorder.size() == 0) return NULL;
        int id = postorder.size() - 1;
        int mid = 0;
        for(mid = 0; mid < inorder.size(); mid ++){
            if(inorder[mid] == postorder[id]) break;
        }
        root->val = postorder[id];
        root->right = dfs(postorder,id,inorder,mid + 1,inorder.size() - 1);
        root->left = dfs(postorder,id,inorder,0,mid - 1);
        return root;
    }
    
    TreeNode *dfs(vector<int> &postorder,int &id,vector<int> &inorder,int sta,int end){
        if(sta > end) return NULL;
        TreeNode *p = new TreeNode(0);
        id --;
        int mid = sta;
        for(mid = sta; mid <= end; mid ++){
            if(postorder[id] == inorder[mid]) break;
        }
        p->val = postorder[id];
        p->right = dfs(postorder,id,inorder,mid + 1,end);
        p->left = dfs(postorder,id,inorder,sta,mid - 1);
        return p;
    }
};
