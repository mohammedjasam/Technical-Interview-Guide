/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value){
    node *q = new node();
    if(!root){
        q->data = value;
       return q;
    }
    if(root->data == value){
        q->data = value;
        q->right = root->right;
        root->right = q;
        return root;
    }
    node *p = root;
 //   node *q = new node();
    while(p){
        if(p->data == value){
            q->data = value;
            q->right = p->right;
            p->right = q;
            break;
        }else if(p->data > value){
            if(p->left)
                p = p->left;
            else{
                q->data = value;
                p->left = q;
                break;
            }
        }else{
           if(p->right)
                p = p->right;
            else{
                q->data = value;
                p->right = q;
                break;
            } 
        }
    }
    return root;
}
