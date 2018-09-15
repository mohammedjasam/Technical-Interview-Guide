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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(!head)
            return NULL;
        int len = 0;
        ListNode *p = head;
        while(p){
            ++ len;
            p = p->next;
        }
        int m = len - n;
        ListNode dump(-1);
        ListNode *q = &dump;
        q->next = head;
        p = head;
        for(int i = 0; i < m; ++ i){
            q = q->next;
            p = p->next;
        }
        q->next = p->next;
        return dump.next;
    }
};



