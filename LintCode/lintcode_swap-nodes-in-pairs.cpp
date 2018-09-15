/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if(!head || !head->next)
            return head;
        ListNode *p, *q, *t;
        ListNode dump(-1);
        p = &dump;
        dump.next = head;
        q = head;
        t = head->next;
        while(q && t){
            p->next = t;
            q->next = t->next;
            t->next = q;
            p = q;
            q = p->next;
            if(q)
                t = q->next;
        }
        return dump.next;
    }
};
