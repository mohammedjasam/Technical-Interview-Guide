/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
    Node *node = new Node();
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if(!head){
        head = node;
    }else if(head->data >= node->data){
        node->next = head;
        head->prev = node;
        head = node;
    }else{
        Node *p = head;
        while(p->next){
            if(p->next->data >= node->data){
                node->next = p->next;
                p->next->prev = node;
                node->prev = p;
                p->next = node;
                return head;
            }
            p = p->next;
        }
        p->next = node;
        node->prev = p;
    }
    return head;
}

