/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand (time(NULL));
        int tot = 0;
        dict.resize(len);
        ListNode *p = head;
        while(p){
            if(tot < len)
                dict[tot] = p->val;
            else{
                int idx = rand()%(tot+1);
                if(idx < len)
                    dict[idx] = p->val;
            }
            p = p->next;
            ++ tot;
        }
        len = min(len, tot);
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return dict[rand()%len];
    }
private:
    vector<int> dict;
    int len = 10000;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
