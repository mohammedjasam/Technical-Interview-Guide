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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        TreeNode *root = new TreeNode(0);
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        int id = 0;
        int mid = 0;
        for(mid = 0; mid < inorder.size(); mid ++){
            if(inorder[mid] == preorder[id]) break;
        }
        root->val = preorder[id];
        root->left = dfs(preorder,id,inorder,0,mid - 1);
        root->right = dfs(preorder,id,inorder,mid + 1,inorder.size() - 1);
        return root;
    }
    
    TreeNode *dfs(vector<int> &preorder,int &id,vector<int> &inorder,int sta,int end){
        if(sta > end) return NULL;
        TreeNode *p = new TreeNode(0);
        id ++;
        int mid = sta;
        for(mid = sta; mid <= end; mid ++){
            if(inorder[mid] == preorder[id]) break;
        }
        p->val = preorder[id];
        p->left = dfs(preorder,id,inorder,sta,mid - 1);
        p->right = dfs(preorder,id,inorder,mid + 1,end);
        return p;
    }
};
