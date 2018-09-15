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
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if(!head || !head->next)
            return head;
        ListNode dump(-1);
        ListNode *prev = &dump, *cur, *p, *q,*tmpp, *tmpq;
        dump.next = head;
        cur = p = prev->next;
        q = prev;
        while(cur->next){
            tmpp = p;
            tmpq = q;
            int val = tmpp->val;
            while(p){
                if(p->val < val){
                    val = p->val;
                    tmpq = q;
                    tmpp = p;
                }
                p = p->next;
                q = q->next;
            }
            if(tmpp != cur){
                tmpq->next = tmpp->next;
                tmpp->next = cur;
                prev->next = tmpp;
                cur = tmpp;
            }
            cur = cur->next;
            prev = prev->next;
            p = cur;
            q = prev;
        }
        return dump.next;
    }
};
