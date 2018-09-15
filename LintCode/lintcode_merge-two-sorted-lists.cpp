/*
*
* Tag: Brute Force
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(!l1 && !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode dump(-1);
        ListNode *cur = &dump;
        ListNode *p1 = l1, *p2 = l2;
        while(p1 && p2){
            if(p1->val <= p2->val){
                cur->next = p1;
                p1 = p1->next;
            }else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        while(p1){
            cur->next = p1;
            p1 = p1->next;
            cur = cur->next;
        }
        while(p2){
            cur->next = p2;
            p2 = p2->next;
            cur = cur->next;
        }
        return dump.next;
    }
};
