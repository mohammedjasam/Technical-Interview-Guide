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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return head;
        int len = 1, cnt = 1;
        ListNode *p,*q;
        p = head;
        while(p->next != NULL) {p = p->next;len ++;}
        len -= n;
        p = head;
        while(cnt < len){
            p = p->next;
            cnt ++;
        }
        q = p->next;
        if(q != NULL) {
            if(head == p && len == 0) head = head->next;
            else p->next = q->next;
        }
        else head = NULL;
        return head;
    }
};
