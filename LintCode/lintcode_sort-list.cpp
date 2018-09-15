/*
*
* Tag: Sort
* Time: O(nlgn)
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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head == NULL)
            return head;
        head = sortlist(head);
        return head;
    }
    
    ListNode *sortlist(ListNode *head){
        int len = 0;
        ListNode *p = head;
        while(p != NULL){
            p = p->next;
            len ++;
        }
        if(len == 1)
            return head;
        p = head;
        ListNode *fhead = head, *shead = head;
        ListNode new_head(-1);
        for(int i = 0; i < len/2 - 1; ++ i){
            p = p->next;
        }
        shead = p->next;
        p->next = NULL;
        fhead = sortlist(fhead);
        shead = sortlist(shead);
        p = &new_head;
        while(fhead && shead){
            if(fhead->val <= shead->val){
                p->next = fhead;
                p = p->next;
                fhead = fhead->next;
            }else{
                p->next = shead;
                p = p->next;
                shead = shead->next; 
            }
        }
        while(fhead){
            p->next = fhead;
            p = p->next;
            fhead = fhead->next;
        }
        while(shead){
            p->next = shead;
            p = p->next;
            shead = shead->next;
        }
        return new_head.next;
    }
};
