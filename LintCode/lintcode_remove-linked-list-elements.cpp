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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        if(!head)
            return head;
        ListNode dump(-1);
        dump.next = head;
        ListNode *p = &dump, *q = head;
        while(q){
            if(q->val == val){
                p->next = q->next;
                delete q;
                q = NULL;
                q = p->next;
            }else{
                p = p->next;
                q = q->next;
            }
        }
        return dump.next;
    }
};
