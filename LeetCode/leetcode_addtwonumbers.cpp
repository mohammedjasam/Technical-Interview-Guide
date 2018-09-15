/*
* Algorithm: Brute force
* Time complexity: O(n)
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head = NULL, *p = NULL;
        head = l1;
        p = l1;
        int c = 0,sum;
        while(l1 != NULL && l2 != NULL)
        {
            sum = l1 ->val + l2 ->val +c;
            p->val = sum%10;
            c = sum/10;
            l1 = l1 ->next;
            l2 = l2 ->next;
            if(l1 != NULL) p = p->next;
        }
        while(l1 != NULL)
        {
            sum = l1 ->val +c;
            p->val = sum%10;
            c = sum/10;
            l1 = l1 ->next;
            if(l1 != NULL) p = p->next;
        }
        if(l2 != NULL) {p ->next = l2;p=p->next;}
        while(l2 != NULL)
        {
            sum = l2 ->val +c;
            p->val = sum%10;
            c = sum/10;
            l2 = l2 ->next;
            if(l2 != NULL) p = p->next;
        }
        if(c){
            ListNode *q = new ListNode(1);
            p->next = q;
        }
        return head;
    }
};
