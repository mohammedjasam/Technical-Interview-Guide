/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
   void connect(TreeLinkNode *root) {
        if(root == NULL) return ;
        
        TreeLinkNode extra(-1);
        
        for(TreeLinkNode *cur = root, *prev = &extra; cur; cur = cur->next){
            if(cur->left != NULL){
                prev->next = cur->left;
                prev = prev->next;
            }
            if(cur->right != NULL){
                prev->next = cur->right;
                prev = prev->next;
            }
        }
       
        connect(extra.next);
    }
};
