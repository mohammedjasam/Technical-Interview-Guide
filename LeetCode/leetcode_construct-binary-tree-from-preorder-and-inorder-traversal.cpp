/*
*
* Improvement
* Tag: DFS
* Time: O(n^2) (can be reduced to O(n))
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
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        
        int id = -1;
        return dfs(preorder, id, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode *dfs(vector<int> &preorder,int &id,vector<int> &inorder,int sta,int end){
        if(sta > end) {
            return NULL;
        }
        
        id ++;
        int mid = sta;
        for(mid = sta; mid <= end; mid ++){
            if(inorder[mid] == preorder[id]) {
                break;
            }
        }
        
        TreeNode *p = new TreeNode(preorder[id]);
        p->left = dfs(preorder,id,inorder,sta,mid - 1);
        p->right = dfs(preorder,id,inorder,mid + 1,end);
        
        return p;
    }
};
