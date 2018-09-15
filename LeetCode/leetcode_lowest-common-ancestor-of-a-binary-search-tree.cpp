/*
*
* Tag: DFS (Iterative)
* Time: O(n)
* Space: O(1)
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
        if(root == NULL || p == NULL || q == NULL){
            return root;
        }
        
        while( (root->val - p->val)*(root->val - q->val) > 0 ) {
            root = root->val < p->val ? root->right : root->left;
        }
        
        return root;
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
        if(p == q || p->val == q->val)
            return p;
        depth[root] = 1;
        parent[root] = NULL;
        if(!find(root, p) || !find(root, q))
            return NULL;
        return LCA(p, q);
    }

    bool find(TreeNode *root, TreeNode *target){
        if(root->val == target->val){
            depth[target] = depth[root];
            return true;
        }else if(target->val < root->val){
            if(!root->left)
                return false;
            depth[root->left] = depth[root] + 1;
            parent[root->left] = root;
            return find(root->left, target);
        }else{
            if(!root->right)
                return false;
            depth[root->right] = depth[root] + 1;
            parent[root->right] = root;
            return find(root->right, target);
        }
    }
    
    TreeNode* LCA(TreeNode* p, TreeNode* q){
        if(depth[p] > depth[q])
            swap(p, q);
        while(depth[p] < depth[q])
            q = parent[q];
        while(parent[p] != parent[q]){
            p = parent[p];
            q = parent[q];
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
