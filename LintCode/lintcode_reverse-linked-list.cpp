/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(!head || !head->next)
            return head;
        int len = 0;
        ListNode *p = head;
        while(p){
            ++ len;
            p = p->next;
        }
        if(len == 2){
            p = head->next;
            p->next = head;
            head->next = NULL;
            return p;
        }
        ListNode *pre = head, *cur = head->next, *next = head->next->next;
        while(next){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        head->next = NULL;
        return cur;
    }
};

