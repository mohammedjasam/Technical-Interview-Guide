/*
*
* Tag: Brute force
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *slow2 = head;
                while(slow2 != slow){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};
