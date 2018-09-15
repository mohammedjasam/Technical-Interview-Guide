/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    if(head == NULL)
        return head;
    Node dump;
    Node *t = &dump, *p = head, *q;
    q = p->next;
    if(position == 0){
        p->next=NULL;
        return q;
    }
    for(int i = 1; i < position; ++ i){
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    return head;
}

