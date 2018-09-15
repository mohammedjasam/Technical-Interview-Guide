/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /**
     * @param head: the given linked list
     * @return: the array that store the values in reverse order 
     */
    vector<int> reverseStore(ListNode * head) {
        vector<int> ans;
        if(head == NULL){
            return ans;
        }
        
        ListNode *point = head;
        while(point != NULL) {
            ans.push_back(point->val);
            point = point->next;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
