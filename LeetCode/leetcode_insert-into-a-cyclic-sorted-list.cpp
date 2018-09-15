/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal, NULL);
        
        if(head == NULL){
            node->next = node;
            return node;
        }
        
        Node *curPointer = head, *nextPointer = head->next;
        if(curPointer == nextPointer){
            head->next = node;
            node->next = head;
            
            return head;
        }
        
        Node *smallestValuePointer = NULL, *smallestValuePrevPointer = NULL;
        bool isBackToHead = false;
        while(!isBackToHead){
            if(curPointer->val <= insertVal && insertVal <= nextPointer->val){
                curPointer->next = node;
                node->next = nextPointer;
                return head;
            }
            
            if(curPointer->val > nextPointer->val){
                smallestValuePrevPointer = curPointer;
                smallestValuePointer = nextPointer;
            }
            
            curPointer = nextPointer;
            nextPointer = nextPointer->next;
            
            if(curPointer == head){
                isBackToHead = true;
            }
        }
        
        if(!smallestValuePointer){
            node->next = head->next;
            head->next = node;
        } else {
            smallestValuePrevPointer->next = node;
            node->next = smallestValuePointer;
        }
        
        return head;
    }
};
