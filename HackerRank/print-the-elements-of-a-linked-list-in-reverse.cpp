/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(n)
*/
/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
#include <vector>

void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    if(head == NULL)
        return ;
    vector<int> arr;
    Node *p = head;
    while(p){
        arr.push_back(p->data);
        p = p->next;
    }
    for(int i = arr.size() - 1; i >= 0; -- i)
        printf("%d\n",arr[i]);
}

