/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    Node *p = head;
    int len = 0;
    while(p){
        p=p->next;
        ++ len;
    }
    len -= positionFromTail;
    p = head;
    for(int i = 0; i < len - 1; ++ i, p = p->next) ;
    return p->data;
}
