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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if(!head || !head->next)
            return true;
        int len = 0;
        ListNode *p = head, *p1, *q1, *t1, *p2, dump(-1);
        while(p){
            ++ len;
            p = p->next;
        }
        if(len == 2)
            return head->val == head->next->val;
        int bnd = (len%2)?(len + 1)/2:len/2;
        dump.next = head;
        p1 = &dump;
        q1 = p1->next;
        t1 = q1->next;
        for(int i = 1; i <= bnd; ++ i){
            q1->next = p1;
            p1 = q1;
            q1 = t1;
            t1 = t1->next;
        }
        head->next = NULL;
        if(len%2)
            p1 = p1->next;
        p2 = q1;
        while(p2){
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
