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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        ListNode *ans = head;
        if(!head)
            return ans;
        ListNode *fast = head, *slow = head;
        ans = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *slow2 = head;
                while(slow2 != slow){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                ans = slow2;
                break;
            }
        }
        return ans;
    }
};
