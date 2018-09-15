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

void Inorder(node *root) {
    if(root->left)
        Inorder(root->left);
    printf("%d ",root->data);
    if(root->right)
        Inorder(root->right);
}
