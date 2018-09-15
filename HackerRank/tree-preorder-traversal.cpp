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

void Preorder(node *root) {
    printf("%d ",root->data);
    if(root->left)
        Preorder(root->left);
    if(root->right)
        Preorder(root->right);
}
