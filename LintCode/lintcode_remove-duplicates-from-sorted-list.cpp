/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head)
            return head;
        ListNode *cur = head, *next = head->next;
        while(next){
            if(cur->val == next->val){
                cur->next = next->next;
            }else{
                cur = next;
            }
            next = next->next;
        }
        return head;
    }
};
