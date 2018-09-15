/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return head;
        unordered_map<RandomListNode *, RandomListNode *> dict;
        dict.clear();
        RandomListNode *cur = head;
        while(cur){
            if(dict.find(cur) == dict.end()){
                RandomListNode *new_node = new RandomListNode(cur->label);
                dict[cur] = new_node;
            }
            cur = cur->next;
        }
        cur = head;
        while(cur){
            if(cur->next != NULL){
                dict[cur]->next = dict[cur->next];
            }
            if(cur->random != NULL){
                dict[cur]->random = dict[cur->random];
            }
            cur = cur->next;
        }
        return dict[head];
    }
};
