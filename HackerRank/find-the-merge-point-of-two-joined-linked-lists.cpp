/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method.
    Node *b = headB;
    while(b->next){
        b = b->next;
    }
    b->next = headB;
    Node *fasta = headA, *slowa = headA, *slowaa = headA;
    while(fasta){
        fasta = fasta->next->next;
        slowa = slowa->next;
        if(fasta == slowa)
            break;
    }
    while(slowa){
        slowa = slowa->next;
        slowaa = slowaa->next;
        if(slowa == slowaa)
            break;
    }
    return slowaa->data;
}

