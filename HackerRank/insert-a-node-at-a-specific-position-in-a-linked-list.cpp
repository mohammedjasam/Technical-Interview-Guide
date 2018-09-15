/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Insert Node at a given position in a linked list 
  The linked list will not be empty and position will always be valid
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
    Node *p = new Node();
    p->data = data;
    p->next = NULL;
    if(head == NULL){
        head = p;
        return head;
    }
    if(position == 0){
        p->next = head;
        head = p;
    }else{
        int len = 0;
        Node *q = head;
        while(len < position - 1){
            q = q->next;
            ++ len;
        }
        p->next = q->next;
        q->next = p;
    }
    return head;
}

