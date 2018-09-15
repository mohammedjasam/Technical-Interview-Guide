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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root)
            return res;
        serDFS(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode dummy(-1);
        TreeNode *parent = &dummy, *root = NULL;
        parent->left = root;
        string::iterator it = data.begin(), nxt;
        int val = 0;
        while(it != data.end()){
            nxt = find(it, data.end(), ',');
            val = stoi(string(it, nxt));
            dserDFS(parent, parent->left, val, true);
            it = nxt + 1;
        }
        return parent->left;
    }
    
private:
    void serDFS(TreeNode* root, string &res){
        res += to_string(root->val)+",";
        if(root->left)
            serDFS(root->left, res);
        if(root->right)
            serDFS(root->right, res);
    }
    
    void dserDFS(TreeNode* parent,TreeNode* root, int val, bool isleft){
        if(root == NULL){
            TreeNode *cur = new TreeNode(val);
            if(isleft){
                parent->left = cur;
            }else{
                parent->right = cur;
            }
            return ;
        }
        if(root->val < val)
            dserDFS(root, root->right, val, false);
        if(root->val > val)
            dserDFS(root, root->left, val, true);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
