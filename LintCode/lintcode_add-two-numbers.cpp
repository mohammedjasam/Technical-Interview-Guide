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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *ans = NULL, *q;
        if(!l1 && !l2)
            return ans;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int c = 0;
        ListNode *p1 = l1, *p2 = l2;
        while(p1 && p2){
            int val = (p1->val + p2->val + c);
            c = val/10;
            ListNode *p = new ListNode(val);
            if(!ans){
                ans = p;
                q = p;
            }else{
                q->next = p;
                q = p;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1){
            int val = (p1->val + c);
            c = val/10;
            ListNode *p = new ListNode(val);
            q->next = p;
            q = p;
            p1 = p1->next;
        }
        
        while(p2){
            int val = (p2->val + c);
            c = val/10;
            ListNode *p = new ListNode(val);
            q->next = p;
            q = p;
            p2 = p2->next;
        }
        
        if(c){
            ListNode *p = new ListNode(c);
            q->next = p;
            q = p;
        }
        return ans;
    }
};
