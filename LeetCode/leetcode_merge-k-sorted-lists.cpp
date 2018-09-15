/*
*
* Tag: Divide and Conquer
* Time: O(nlgk)
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)
            return NULL;
        int cur_len = lists.size(), half_len = 0;
        ListNode *l1 = NULL, *l2 = NULL, *merge_list = NULL;
        while(cur_len > 1){
            half_len = (cur_len + 1)/2;
            for(int i = 0; i < half_len && i + half_len < cur_len; ++ i){
                l1 = lists[i], l2 = lists[i + half_len];
                merge_list = mergeTwoLists(l1, l2);
                lists[i] = merge_list;
            }
            cur_len = half_len;
        }
        return lists[0];
    }
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode dump(-1);
        ListNode *cur = &dump;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while(l1){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        return dump.next;
    }
};

/*
*
* Tag: Greedy (Priority Queue)
* Time: O(nlgn)
* Space: O(m) where m is the length of lists.
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
private:
    struct comparatorOfListNode{
        bool operator() (const ListNode *a, const ListNode *b){
            return b->val <= a->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0){
            return NULL;
        }
        
        ListNode dummy(-1);
        ListNode *p = &dummy;
        priority_queue<ListNode *, vector<ListNode *>, comparatorOfListNode> pq;
        for(ListNode *list : lists){
            if(list != NULL){
                pq.push(list);
            }
        }
        
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            
            p->next = node;
            p = p->next;
            if(node->next != NULL){
                ListNode *q = node->next;
                pq.push(q);
            }
        }
        
        return dummy.next;
    }
};
