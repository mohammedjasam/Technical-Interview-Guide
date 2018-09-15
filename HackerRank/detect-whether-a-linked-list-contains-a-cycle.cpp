/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int HasCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
    if(!head)
        return 0;
    Node *fast = head, *slow = head;
    while(fast){
        fast = fast->next;
        if(!fast)
            return 0;
        fast = fast->next;
        slow = slow->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}

