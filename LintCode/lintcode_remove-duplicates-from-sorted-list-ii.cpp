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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head)
            return head;
        ListNode dump(-1);
        ListNode *cur = &dump;
        ListNode *p = head, *q;
        cur->next = head;
        q = p->next;
        while(p && q){
            bool isduplicate = false;
            while(p && q && p->val == q->val){
                p->next = q->next;
                q = q->next;
                isduplicate = true;
            }
            if(isduplicate){
                cur->next = p->next;
    //            cur = cur->next;
            }else{
                cur = p;
            }
            p = p->next;
            if(p)
                q = p->next;
        }
        return dump.next;
    }
};
