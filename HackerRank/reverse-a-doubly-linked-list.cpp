/*
*
* Tag: Linked List
* Time: O(n)
* Space: O(1)
*/
/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

void print(Node *head){
    Node *p = head;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    puts("");
}

Node* Reverse(Node* head){
    // Complete this function
    // Do not write the main method.
    if(!head || !head->next)
        return head;
    Node *p = head, *q = head->next, *r;
    Node dumy;
    r = &dumy;
    r->next = head;
    head->prev = r;
 //   print(dumy.next);
 //   head->next = NULL;
    while(q){
        p->next = q->next;
        q->next = r->next;
        q->prev = r;
        r->next->prev = q;
        r->next = q;
        q = p->next;
    }
    p->next = NULL;
    r = &dumy;
    r->next->prev = NULL;
    return dumy.next;
}

