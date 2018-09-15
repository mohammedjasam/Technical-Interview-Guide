/*
*
* Tag: O(n)
* Time: O(n)
* Space: O(1)
*/
/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    if(!head)
        head = node;
    else{
        Node *p = head;
        while(p->next)
            p = p->next;
        p->next = node;
    }
    return head;
}
