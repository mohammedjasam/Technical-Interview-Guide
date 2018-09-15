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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        if(!head || v1 == v2)
            return head;
        int len = 0;
        ListNode *p1 = NULL, *p2 = NULL, *prep1 = NULL, *prep2 = NULL;
        ListNode dump(-1);
        dump.next = head;
        p1 = &dump;
        while(p1->next){
            if(p1->next->val == v1){
                prep1 = p1;
                break;
            }
            p1 = p1->next;
        }
        if(prep1 == NULL)
            return head;
        p2 = &dump;
        while(p2->next){
            if(p2->next->val == v2){
                prep2 = p2;
                break;
            }
            p2 = p2->next;
        }
        if(prep2 == NULL)
            return head;
        
        ListNode *curp1 = prep1->next, *curp2 = prep2->next;
        
        if(curp1 == prep2){
            prep1->next = curp2;
            curp1->next = curp2->next;
            curp2->next = curp1;
            return dump.next;
        }
        if(curp2 == prep1){
            prep2->next = curp1;
            curp2->next = curp1->next;
            curp1->next = curp2;
            return dump.next;
        }
        
        prep1->next = curp1->next;
        prep2->next = curp2->next;
        curp1->next = prep2->next;
        prep2->next = curp1;
        curp2->next = prep1->next;
        prep1->next = curp2;
        
        return dump.next;
    }
};
