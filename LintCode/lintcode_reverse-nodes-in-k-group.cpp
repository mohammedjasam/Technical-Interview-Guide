
/*
*
* Tag: Brute Force
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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k < 2)
            return head;
        ListNode tmphead(-1);
        tmphead.next = head;
        
        for(ListNode *prev = &tmphead, *end = head; end; end = prev->next){
            for(int i = 1; i < k && end; ++ i)
                end = end->next;
            if(end == NULL)
                break;
            prev = reverse(prev, prev->next, end);
        }
        
        return tmphead.next;
    }
    
    ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end){
        ListNode *end_next = end->next;
        for(ListNode *p = begin, *cur = p->next, *next = cur->next; cur != end_next; p = cur, cur = next, next = next?next->next:NULL){
            cur->next = p;
        }
        begin->next = end_next;
        prev->next = end;
        return begin;
    }
};
