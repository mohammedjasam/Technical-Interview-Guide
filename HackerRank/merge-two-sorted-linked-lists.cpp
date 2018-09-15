/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method
    Node *a = headA, *b = headB, *p;
    Node dump;
    dump.next = NULL;
    p = &dump;
    while(a && b){
        if(a->data <= b->data){
            p->next = a;
            p = a;
            a = a->next;
        }else{
            p->next = b;
            p = b;
            b = b->next;
        }
    }
    while(a){
        p->next = a;
        p = a;
        a = a->next; 
    }
    while(b){
        p->next = b;
        p = b;
        b = b->next;
    }
    return dump.next;
}

