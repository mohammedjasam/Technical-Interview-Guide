/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
void dfs(node * root, int &ans, int dep){
    if(!root){
        return ;
    }
    ++ dep;
    ans = max(ans, dep);
    if(root->left)
        dfs(root->left, ans, dep);
    if(root->right)
        dfs(root->right, ans, dep);
}

int height(node * root){
    int ans = 0;
    dfs(root, ans, 0);
    return ans;
}
