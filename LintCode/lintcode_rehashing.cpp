/*
*
* Tag: Hash
* Time:O(n)
* Space: O(1)
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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        vector<ListNode*> newHash;
        if(hashTable.size() == 0)
            return newHash;
        int cap = hashTable.size();
        int newcap = 2*cap;
        newHash.resize(newcap);
        for(int i = 0; i < cap; ++ i){
            if(hashTable[i] == NULL)
                continue;
            ListNode *p = hashTable[i];
            while(p){
                ListNode *new_node = new ListNode(p->val);
                int key = getKey(p->val, newcap);
                if(newHash[key]){
                    ListNode *q = newHash[key];
                    while(q->next) q = q->next;
                //    new_node->next = newHash[key]->next;
                    q->next = new_node;
                }else
                    newHash[key] = new_node;
                p = p->next;
            }
        }
        return newHash;
    }
    
    int getKey(int val, int cap){
        int key = valÊp;
        if(key<0)
            key = (key + cap)Êp;
        return key;
    }
};

