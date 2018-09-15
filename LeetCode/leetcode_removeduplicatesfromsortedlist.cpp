
/*
* Algorithm: O(n)
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode *p, *q;
        p = head;
        q = p->next;
        while(p->next!=NULL)
        {
            if(p->val == q->val){
                p->next = q->next;
                q = p->next;
                continue;
            }else{
                p=q;
                q=q->next;
            }
        }
        return head;
    }
};
