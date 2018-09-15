/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/
/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void Print(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    if(head == NULL)
        return ;
    Node *p = head;
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
}
