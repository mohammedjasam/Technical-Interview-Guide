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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return ;
        
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        
        slow = reverse(slow);
        
        ListNode *cur = head;
        while(cur->next){
            ListNode *tmp = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = tmp;
            cur = tmp;
        }
        cur->next = slow;
    }
    
    ListNode* reverse(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *prev = head;
        for(ListNode *cur = head->next, *next = cur->next; cur; prev = cur,cur = next, next = next? next->next:NULL){
            cur->next = prev;
        }
        head->next = NULL;
        return prev;
    }
    
};
