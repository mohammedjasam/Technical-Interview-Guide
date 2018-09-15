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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head == NULL)
            return head;
        ListNode *prev, *prevb, *pb, *fd, *prevfd;
        prev = prevb = pb = head;
        if(pb->val < x){
            pb = prevb->next;
            while(pb != NULL){
                if(pb->val >= x)
                    break;
                pb = pb->next;
                prevb = prevb->next;
            }
        }
        if(pb == NULL)
            return head;
        ListNode add(-1);
        prev = &add;
        prevfd = pb;
        fd = pb->next;
        while(fd != NULL){
            if(fd->val < x){
                prev->next = fd;
                prevfd->next = fd->next;
                prev = prev->next;
            }else
                prevfd = prevfd->next;
            fd = fd->next;
        }
        if(pb == head){
            prev->next = head;
            return add.next;
        }else{
            prev->next = prevb->next;
            prevb->next = add.next;
            return head;
        }
    }
};
