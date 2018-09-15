/*
*
* Tag: Data Structure (Hash)
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
    int numComponents(ListNode* head, vector<int>& G) {
        int numOfComponents = 0;
        
        ListNode *p = head;
        set<int> setG(G.begin(), G.end());
        bool lastValueIsInG = false;
        while(p != NULL){
            int value = p->val;
            if(setG.count(value) != 0){
                lastValueIsInG = true;
            } else {
                if(lastValueIsInG)
                    ++ numOfComponents;
                lastValueIsInG = false;
            }
            p = p->next;
        }
        
        return lastValueIsInG ? numOfComponents + 1 : numOfComponents;
    }
};
