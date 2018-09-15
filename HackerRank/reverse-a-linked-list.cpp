/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    if(!head || !head->next)
        return head;
    Node dump;
    dump.next = head;
    Node *p, *q = head->next, *r = &dump;
    head->next = NULL;
    p = q->next;
    while(q){
        q->next = r->next;
        r->next = q;
        q = p;
        if(!q)
            break;
        p = p->next;
    }
    return dump.next;
}

