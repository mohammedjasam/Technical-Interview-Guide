/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/


void Postorder(node *root) {
    if(root->left)
      Postorder(root->left);
    if(root->right)
      Postorder(root->right);
    printf("%d ",root->data);
}
