/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
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
    ListNode* plusOne(ListNode* head) {
        ListNode* ans = new ListNode(1);
        if(!head)
            return ans;
        int c = 0;
        dfs(head, c);
        if(c)
            ans->next = head;
        else
            ans = head;
        return ans;
    }
private:
    void dfs(ListNode* p, int &c){
        if(p->next == NULL)
            ++ p->val;
        else{
            dfs(p->next, c);
            p->val = p->val + c;
        }
        c = p->val>=10?1:0;
        p->val = p->val%10;
    } 
};
