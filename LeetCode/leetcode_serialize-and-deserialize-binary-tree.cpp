/*
*
* Tag: BFS
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
        string ans = "";
        if(!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(!cur){
                ans += "#,";
            }else{
                ans += to_string(cur->val)+",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode **> q;
        TreeNode *root;
        q.push(&root);
        string::iterator it = data.begin();
        while(!q.empty() && it != data.end()){
            TreeNode **cur = q.front();
            q.pop();
            if(*it == '#'){
                *cur = NULL;
                advance(it, 2);
            }else{
                string::iterator nxt = find(it, data.end(), ',');
                *cur = new TreeNode(stoi(string(it, nxt)));
                q.push(&((*cur)->left));
                q.push(&((*cur)->right));
                it = nxt + 1;
            }
        }
        return root;
    }
};
