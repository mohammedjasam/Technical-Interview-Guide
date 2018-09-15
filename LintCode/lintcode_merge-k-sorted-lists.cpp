/*
*
* Tag: Data Structure (Heap)
* Time: O(mlgm) where m = n*k
* Space: O(m)
*/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(!lists.size())
            return NULL;
        ListNode dump(-1);
        ListNode *p = &dump;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for(int i = 0; i < lists.size(); ++ i){
            if(lists[i] == NULL)
                continue;
            ListNode *p = lists[i];
            while(p){
                pq.push(p);
                p = p->next;
            }
        }
        while(!pq.empty()){
            ListNode *u = pq.top();
            pq.pop();
            p->next = u;
            p = p->next;
        }
        return dump.next;
    }
    
    struct cmp{
        bool operator() (const ListNode *a, const ListNode *b){
        	return a->val > b->val;  
        }
    };  
};
