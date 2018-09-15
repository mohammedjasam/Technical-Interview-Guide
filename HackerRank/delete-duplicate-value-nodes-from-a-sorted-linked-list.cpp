/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    if(!head)
        return head;
    Node *p = head, *q;
    q = p->next;
    while(q){
        if(p->data == q->data){
            p->next = q->next;
            q = p->next;
        }else{
            p = q;
            q = q->next;
        }
    }
    return head;
}

