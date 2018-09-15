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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(!head || !k)
            return head;
        int len = 0;
        ListNode *p = head;
        while(p->next){
            p = p->next;
            ++ len;
        }
        ++ len;
        k%=len;
        if(!k)
            return head;
        p->next = head;
        int new_head = len - k - 1;
        p = head;
        while(new_head){
            p = p->next;
            -- new_head;
        }
        ListNode *ans = p->next;
        p->next = NULL;
        return ans;
    }
};
