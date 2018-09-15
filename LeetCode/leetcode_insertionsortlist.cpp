/*
* Algorithm: Brute force
* Time complexity: O(n^2)
* Memory complexity: O(1)
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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == NULL || head->next == NULL)return head;
        ListNode *p = head->next, *pstart = new ListNode(0), *pend = head;
        pstart->next = head; 
        while(p != NULL)
        {
            ListNode *tmp = pstart->next, *pre = pstart;
            while(tmp != p && p->val >= tmp->val)
                {tmp = tmp->next; pre = pre->next;}
            if(tmp == p)pend = p;
            else
            {
                pend->next = p->next;
                p->next = tmp;
                pre->next = p;
            }
            p = pend->next;
        }
        head = pstart->next;
        delete pstart;
        return head;
    }
};
