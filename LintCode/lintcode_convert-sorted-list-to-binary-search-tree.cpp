/*
*
* Tag: Linked List
* Time: O(nlgn) (Worst: O(nlgn))
* Space: O(lgn)
*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
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
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int len = 0;
        if(!head)
            return NULL;
        ListNode *p = head;
        while(p){
            len ++;
            p = p->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
    
private:
    TreeNode *sortedListToBST(ListNode*& list, int sta, int end){
        if(sta > end) return NULL;
        
        int mid = sta + (end - sta) / 2;
        TreeNode *leftChild = sortedListToBST(list, sta, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = sortedListToBST(list, mid + 1, end);
        return parent;
    }
};
