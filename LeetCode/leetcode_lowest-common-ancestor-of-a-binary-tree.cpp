/*
*
* Tag: DFS
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q){
            return root;
        }
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};


/*
*
* Tag: DFS + Hash
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(p == q)
            return p;
        depth[root] = 1;
        parent[root] = NULL;
        if(!find(root, p) || !find(root, q))
            return NULL;
        return LCA(p, q);
    }
    
    bool find(TreeNode *root, TreeNode *target){
        if(root == target){
            depth[target] = depth[root];
            return true;
        }
        if(root->left){
            depth[root->left] = depth[root] + 1;
            parent[root->left] = root;
            if(find(root->left, target))
                return true;
        }
        if(root->right){
            depth[root->right] = depth[root] + 1;
            parent[root->right] = root;
            if(find(root->right, target))
                return true;
        }
        return false;
    }
    
    TreeNode* LCA(TreeNode *p, TreeNode *q){
        if(depth[p] > depth[q])
            swap(p, q);
        while(depth[p] < depth[q])
            q = parent[q];
        while(parent[p] != parent[q]){
            p = parent[p];
            q= parent[q];
        }
        if(p == q)
            return p;
        else
            return parent[p];
    }
private:
unordered_map<TreeNode *, int> depth;
unordered_map<TreeNode *, TreeNode *> parent;
};
