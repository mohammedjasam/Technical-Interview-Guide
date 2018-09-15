/*
*
* Tag: BFS
* Time: O(n)
* Space: O(n)
*/
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/
#include<queue>
void LevelOrder(node * root){
    queue<node *> q;
    bool isfirst = true;
    q.push(root);
    while(!q.empty()){
        node *tmp = q.front();
        q.pop();
        if(!isfirst)
            printf(" ");
        printf("%d",tmp->data);
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
        isfirst = false;
    }
}
