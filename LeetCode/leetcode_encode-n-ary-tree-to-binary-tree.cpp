/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        TreeNode *binaryTreeRoot = NULL;
        if(root == NULL){
            return binaryTreeRoot;
        }
        
        binaryTreeRoot = new TreeNode(root->val);
        queue<TreeNode *> bq;
        bq.push(binaryTreeRoot);
        
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            Node *cur = q.front();
            q.pop();
            
            TreeNode *newCur = bq.front();
            bq.pop();
            
            if(cur->children.empty()){
                continue;
            }
            
            int childIndex = 0;
            newCur->left = new TreeNode(cur->children[childIndex]->val);
            bq.push(newCur->left);
            q.push(cur->children[childIndex]);
            
            TreeNode *pointer = newCur->left;
            for(childIndex = 1; childIndex < cur->children.size(); ++ childIndex){
                pointer->right = new TreeNode(cur->children[childIndex]->val);
                pointer = pointer->right;
                
                bq.push(pointer);
                q.push(cur->children[childIndex]);
            }
        }
        
        return binaryTreeRoot;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        Node *nodeRoot = NULL;
        if(root == NULL){
            return nodeRoot;
        }
        
        nodeRoot = new Node(root->val);
        queue<Node *> q;
        q.push(nodeRoot);
        
        queue<TreeNode *> bq;
        bq.push(root);
        while(!bq.empty()){
            TreeNode *cur = bq.front();
            bq.pop();
            
            Node *newCur = q.front();
            q.pop();
            
            if(cur->left == NULL){
                continue;
            }
            
            TreeNode *pointer = cur->left;
            bq.push(pointer);
            newCur->children.push_back(new Node(pointer->val));
            q.push(newCur->children.back());
            pointer = pointer->right;
            
            while(pointer != NULL){
                bq.push(pointer);
                newCur->children.push_back(new Node(pointer->val));
                q.push(newCur->children.back());
                pointer = pointer->right;
            }
        }
        
        return nodeRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
