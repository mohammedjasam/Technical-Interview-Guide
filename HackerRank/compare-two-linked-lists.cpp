/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method
    if(headA == NULL && headB == NULL)
        return 1;
    if(headA == NULL || headB == NULL)
        return 0;
    Node *a = headA, *b = headB;
    while(a && b){
        if(a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }
    if(!a && !b)
        return 1;
    else
        return 0;
}

