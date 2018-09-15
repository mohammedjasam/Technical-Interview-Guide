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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        if(!headA || !headB)
            return NULL;
        if(headA == headB)
            return headA;
        ListNode *ap = headA;
        while(ap->next){
            ap = ap->next;
        }
        ap->next = headB;
        ListNode* fast = headA, *slow = headA;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *slow2 = headA;
                while(slow != slow2){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                ap->next = NULL;
                return slow;
            }
        }
        ap->next = NULL;
        return NULL;
    }
};
