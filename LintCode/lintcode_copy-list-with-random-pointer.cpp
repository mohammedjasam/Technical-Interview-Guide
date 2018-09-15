/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(!head)
            return head;
        unordered_map<RandomListNode *, RandomListNode *> mp;
        RandomListNode *p = head;
        while(p){
            RandomListNode *q = new RandomListNode(p->label);
            mp[p] = q;
            p = p->next;
        }
        p = head;
        while(p){
            if(p->next){
                mp[p]->next = mp[p->next];
            }
            if(p->random){
                mp[p]->random = mp[p->random];
            }
            p = p->next;
        }
        return mp[head];
    }
};
