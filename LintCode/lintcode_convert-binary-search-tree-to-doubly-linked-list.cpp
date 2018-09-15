/*
*
* Tag: DFS
* Time: O(n)
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        vector<int> ans;
        if(!root)
            return NULL;
        if(root->left)
            dfs(root->left, ans);
        ans.push_back(root->val);
        if(root->right)
            dfs(root->right, ans);
        DoublyListNode dump(-1);
        DoublyListNode* cur = &dump;
        for(int i = 0; i < ans.size(); ++ i){
            DoublyListNode *nxt = new DoublyListNode(ans[i]);
            cur->next = nxt;
            nxt->prev = cur;
            cur = cur->next;
        }
        dump.next->prev = NULL;
        return dump.next;
    }
    
    void dfs(TreeNode *root, vector<int> &ans){
        if(root->left)
            dfs(root->left, ans);
        ans.push_back(root->val);
        if(root->right)
            dfs(root->right, ans);
    }

};



